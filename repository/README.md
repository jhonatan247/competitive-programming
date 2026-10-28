# Problem library

This is a small local web application for browsing the generated competitive programming problem library.

## Run locally

From this directory:

```sh
npm start
```

Open <http://localhost:3000>. The app reads `data/problem-library.json` the first time it is opened and stores the result in browser local storage. Later visits use the stored copy and do not request the source file again.

Use **Download data** to export the current local copy as `problem-library.json`. This makes it possible to preserve future metadata edits and replace the repository data file with the downloaded file.
