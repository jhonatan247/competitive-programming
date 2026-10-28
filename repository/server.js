import { createReadStream } from "node:fs";
import { promises as fs } from "node:fs";
import { createServer } from "node:http";
import { extname, join, normalize, relative } from "node:path";
import { fileURLToPath } from "node:url";

const root = fileURLToPath(new URL(".", import.meta.url));
const port = Number(process.env.PORT) || 3000;
const contentTypes = {
  ".css": "text/css; charset=utf-8",
  ".html": "text/html; charset=utf-8",
  ".js": "text/javascript; charset=utf-8",
  ".json": "application/json; charset=utf-8",
};

function getFilePath(requestUrl) {
  const requestedPath = decodeURIComponent(new URL(requestUrl, "http://localhost").pathname);
  const pathname = requestedPath === "/" ? "/index.html" : requestedPath;
  const filePath = normalize(join(root, pathname));
  const relativePath = relative(root, filePath);

  if (relativePath.startsWith("..") || relativePath.includes(`..${normalize("/")}`)) {
    return null;
  }
  return filePath;
}

const server = createServer(async (request, response) => {
  if (request.method !== "GET") {
    response.writeHead(405, { Allow: "GET" });
    response.end("Method Not Allowed");
    return;
  }

  try {
    const filePath = getFilePath(request.url);
    if (!filePath) {
      response.writeHead(403);
      response.end("Forbidden");
      return;
    }

    const file = await fs.stat(filePath);
    if (!file.isFile()) {
      response.writeHead(404);
      response.end("Not Found");
      return;
    }

    response.writeHead(200, {
      "Cache-Control": "no-cache",
      "Content-Type": contentTypes[extname(filePath)] || "application/octet-stream",
    });
    createReadStream(filePath).pipe(response);
  } catch (error) {
    if (error.code === "ENOENT") {
      response.writeHead(404);
      response.end("Not Found");
      return;
    }
    console.error("Unable to serve request:", error);
    response.writeHead(500);
    response.end("Internal Server Error");
  }
});

server.listen(port, () => {
  console.log(`Problem library is available at http://localhost:${port}`);
});
