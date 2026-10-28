const STORAGE_KEY = "competitive-programming.problem-library";
const DATA_URL = "/data/problem-library.json";

const state = {
  data: null,
  section: null,
  path: [],
};

const elements = {
  breadcrumb: document.querySelector("#breadcrumb"),
  download: document.querySelector("#download-button"),
  entries: document.querySelector("#entries"),
  itemCount: document.querySelector("#item-count"),
  status: document.querySelector("#status"),
  tabs: document.querySelector("#section-tabs"),
};

function setStatus(message, isError = false) {
  elements.status.textContent = message;
  elements.status.classList.toggle("error", isError);
}

function isLibraryData(value) {
  return value !== null && typeof value === "object" && !Array.isArray(value);
}

async function loadLibrary() {
  const storedData = localStorage.getItem(STORAGE_KEY);
  if (storedData) {
    try {
      const parsedData = JSON.parse(storedData);
      if (isLibraryData(parsedData)) {
        setStatus("Loaded from this browser");
        return parsedData;
      }
    } catch {
      localStorage.removeItem(STORAGE_KEY);
    }
  }

  const response = await fetch(DATA_URL);
  if (!response.ok) {
    throw new Error(`Could not load ${DATA_URL} (${response.status})`);
  }
  const data = await response.json();
  if (!isLibraryData(data)) {
    throw new Error("The problem library must contain a JSON object.");
  }
  localStorage.setItem(STORAGE_KEY, JSON.stringify(data));
  setStatus("Loaded from the repository and saved in this browser");
  return data;
}

function displayName(key, item) {
  return item && typeof item.title === "string" ? item.title : key;
}

function getCurrentNode() {
  let node = { contents: state.data[state.section] };
  for (const segment of state.path) {
    node = node?.contents?.[segment];
  }
  return node || {};
}

function createButton(className, label, onClick) {
  const button = document.createElement("button");
  button.className = className;
  button.type = "button";
  button.textContent = label;
  button.addEventListener("click", onClick);
  return button;
}

function renderTabs() {
  elements.tabs.replaceChildren();
  elements.tabs.setAttribute("role", "tablist");
  for (const section of Object.keys(state.data)) {
    const tab = createButton("tab", displayName(section, state.data[section]), () => {
      state.section = section;
      state.path = [];
      render();
    });
    tab.classList.toggle("active", section === state.section);
    tab.setAttribute("aria-selected", String(section === state.section));
    tab.setAttribute("role", "tab");
    elements.tabs.append(tab);
  }
}

function renderBreadcrumb() {
  elements.breadcrumb.replaceChildren();
  const crumbs = [{ label: displayName(state.section, state.data[state.section]), path: [] }];
  let node = { contents: state.data[state.section] };
  state.path.forEach((segment, index) => {
    node = node.contents[segment];
    crumbs.push({ label: displayName(segment, node), path: state.path.slice(0, index + 1) });
  });

  crumbs.forEach((crumb, index) => {
    if (index > 0) {
      const separator = document.createElement("span");
      separator.className = "breadcrumb-separator";
      separator.textContent = "/";
      elements.breadcrumb.append(separator);
    }
    const button = createButton("breadcrumb-button", crumb.label, () => {
      state.path = crumb.path;
      render();
    });
    button.classList.toggle("current", index === crumbs.length - 1);
    button.setAttribute("aria-current", index === crumbs.length - 1 ? "page" : "false");
    elements.breadcrumb.append(button);
  });
}

function renderEntries() {
  const node = getCurrentNode();
  const entries = [
    ...Object.entries(node.contents || {}).map(([key, item]) => ({ key, item, type: "folder" })),
    ...Object.entries(node.problems || {}).map(([key, item]) => ({ key, item, type: "problem" })),
  ];
  elements.entries.replaceChildren();
  elements.itemCount.textContent = `${entries.length} ${entries.length === 1 ? "item" : "items"}`;

  if (!entries.length) {
    const empty = document.createElement("p");
    empty.className = "empty-state";
    empty.textContent = "There are no entries in this folder.";
    elements.entries.append(empty);
    return;
  }

  entries.forEach(({ key, item, type }) => {
    const card = createButton(`entry-card entry-${type}`, "", () => {
      if (type === "folder") {
        state.path = [...state.path, key];
        render();
      }
    });
    card.disabled = type === "problem";
    const icon = document.createElement("span");
    icon.className = "entry-icon";
    icon.setAttribute("aria-hidden", "true");
    icon.textContent = type === "folder" ? "" : "</>";
    const details = document.createElement("span");
    const title = document.createElement("span");
    title.className = "entry-title";
    title.textContent = displayName(key, item);
    details.append(title);
    card.append(icon, details);
    if (type === "problem") {
      card.setAttribute("aria-label", `Problem ${displayName(key, item)}`);
    }
    elements.entries.append(card);
  });
}

function render() {
  renderTabs();
  renderBreadcrumb();
  renderEntries();
}

function downloadData() {
  const blob = new Blob([`${JSON.stringify(state.data, null, 4)}\n`], { type: "application/json" });
  const url = URL.createObjectURL(blob);
  const link = document.createElement("a");
  link.href = url;
  link.download = "problem-library.json";
  link.click();
  URL.revokeObjectURL(url);
  setStatus("Downloaded the current library data");
}

elements.download.addEventListener("click", downloadData);

loadLibrary()
  .then((data) => {
    state.data = data;
    state.section = Object.keys(data)[0];
    if (!state.section) {
      throw new Error("The problem library does not contain any sections.");
    }
    render();
  })
  .catch((error) => {
    console.error(error);
    setStatus(error.message, true);
    elements.entries.replaceChildren();
  });
