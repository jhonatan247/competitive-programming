# Problem library

This is a small local web application for browsing the generated competitive programming problem library.

## Run locally

From this directory:

```sh
npm start
```

Open <http://localhost:3000>. The app reads `data/problem-library.json` the first time it is opened and stores the result in browser local storage. Later visits use the stored copy and do not request the source file again.

Use **Download data** to export the current local copy as `problem-library.json`. This makes it possible to preserve future metadata edits and replace the repository data file with the downloaded file.

## Git hook

This project uses [Husky](https://typicode.github.io/husky/) to refresh `data/problem-library.json` before every push. If the generated data changes, the hook stages and commits only that file so the update is included in the push.

Install the dependencies from this directory to configure the hook:

```sh
npm install
```

The hook requires `python3` and uses the problem sources in the parent repository. If refreshing the data or creating the generated-data commit fails, the push is stopped and the error is shown.
