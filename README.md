# Competitive Programming Workspace

This repository is a personal competitive programming (CP) workspace for solving problems, training, building a reusable C++ library, and improving the speed and quality of the programming experience.

It is organized so that problem solutions, reusable tools, editor configuration, and progress tracking can evolve together while remaining useful on any computer with the required dependencies installed.

## Repository Layout

| Directory | Purpose |
| --- | --- |
| [`learning/`](learning/) | Solved learning exercises and experiments. These files are personal work and should remain untouched by automated tools. |
| [`training/`](training/) | Solved contest and practice problems. These files are personal work and should remain untouched by automated tools. |
| [`library/`](library/) | Reusable C++ algorithms, data structures, templates, and local debugging helpers. |
| [`scripts/`](scripts/) | Shell and Python utilities for configuration, compilation, testing, stress testing, and contest workflows. |
| [`config/`](config/) | Vim configuration and C++ snippets. |
| [`repository/`](repository/) | Local Node.js application for browsing and managing the problem library. |

## Setup

The setup script configures the Vim environment, shell aliases, compiler include paths, executable permissions, and the external AtCoder Library dependency:

```sh
bash scripts/config.sh
```

The setup is intended for WSL Ubuntu and macOS. Run it from a shell where `curl`, `git`, Vim, and the required C++ and Node.js tooling are available. Review the script before running it if your local shell configuration or installation paths differ.

The script expects this repository at `~/cp`, because it adds aliases and paths based on that location.

After setup, reload the shell configuration:

```sh
source ~/.zshrc
```

The script adds `~/cp/scripts/` to `PATH`, so utilities such as `build.sh`, `compile.sh`, `stress.sh`, and `in.sh` can be called from any problem directory. It also adds `~/cp/library` to `CPLUS_INCLUDE_PATH` and links the Vim configuration and snippets into their expected locations.

## C++ Workflow

The repository uses C++ for contest solutions and library code. The setup adds `library/` to the C++ include path, so library headers can be included by their path relative to that directory:

```cpp
#include "algo/modular.h"
```

From a problem directory, compile a source file with:

```sh
build.sh problem
```

Useful build modes are:

```sh
build.sh --debug problem
build.sh --verbose problem
build.sh --debug --verbose problem
```

To expand local quoted includes into a single source file suitable for submission to an online judge:

```sh
compile.sh path/to/problem.cpp
```

This writes `path/to/problem_compiled.cpp` and performs a syntax/build check. The generated file is an artifact for submission or inspection and should not be treated as a reusable library source.

## Scripts

The [`scripts/`](scripts/) directory contains the main CP workflow tools:

- `config.sh` configures the environment and links editor files.
- `build.sh` compiles a C++ problem with optimized, debug, or verbose settings.
- `compile.sh` inlines local C++ includes into a submission-ready source file.
- `code.sh`, `in.sh`, `interact.sh`, `runner.py`, `stress.sh`, and `validate.sh` support common local problem-solving and testing workflows.
- `count.sh` provides repository counting utilities.

Scripts should remain portable between WSL Ubuntu and macOS and should provide clear errors when inputs or dependencies are missing.

## Vim Workflow

Most scripts are designed to be accessed directly from Vim, so a C++ problem can be edited, compiled, tested, stress-tested, and prepared for submission without leaving the editor.

The configuration in [`config/.vimrc`](config/.vimrc) includes:

- Automatic insertion of [`library/templates/problem.cpp`](library/templates/problem.cpp) when creating a new `.cpp` file.
- `<F8>`: quick build with `build.sh`.
- `<F9>`: verbose debug build and run with `build.sh --verbose --debug`.
- `<F10>`: debug build and run with `build.sh --debug`.
- `<F7>`: run an existing stress-test setup.
- `<F6>`: compile the solution, slow solution, and generator, then run stress testing.
- `<F4>`: inline local library includes into a `*_compiled.cpp` file, copy the result to the clipboard, and open it in a split.
- `:Gdb`: compile and run the current file with a basic `g++` debug command.

The function-key mappings work in normal, insert, and visual mode for C++ files. The stress-test mappings expect the conventional `<problem>`, `<problem>_slow`, and `<problem>_gen` files in the current directory.

The space key is the Vim leader. Useful leader mappings include:

| Mapping | Action |
| --- | --- |
| `<Space>w` | Save the current file |
| `<Space>e` | Open the current directory in netrw |
| `<Space>n` | Open a vertical split |
| `<Space>p` | Replace `~/in` with clipboard contents |
| `<Space>r` | Reset `~/in` to a single `0` |
| `<Space>t` | Add clipboard contents as the next test case in `~/in` |
| `<Space>s` | Reload `~/.vimrc` |

`~/in` is the shared input file used by the build-and-run workflow. The configuration also provides familiar save, select-all, copy, cut, undo, and escape mappings, plus UltiSnips support for the C++ snippets.

## Shell Shortcuts

`config.sh` adds the following aliases to `~/.zshrc` for quick navigation and tool access:

| Alias | Action |
| --- | --- |
| `atc` | Open the AtCoder training directory |
| `cfc` | Open Codeforces contests |
| `cfp` | Open Codeforces problems |
| `gym` | Open gym training |
| `rpc` | Open the newest RPC directory |
| `train` | Open the newest Codeforces problems directory |
| `unal-l` / `unal-t` | Open UNAL learning / training |
| `lib` | Open the library in Vim |
| `scripts` | Open the scripts in Vim |
| `code` | Run `code.sh` |
| `config` | Run `scripts/config.sh` |
| `count` | Run `count.sh` |
| `in` | Run `in.sh` |
| `src` | Reload `~/.zshrc` |

There are also convenience aliases for opening frequently edited files: `vconfig`, `vdebug`, `vimrc`, `vsnip`, `vsrc`, and `vtemp`.

## C++ Library

The [`library/`](library/) directory contains general-purpose C++ components. Additions should be:

- Self-contained and easy to reuse.
- Clear to include and use in a contest solution.
- Efficient enough for competitive programming.
- Encapsulated where classes or data structures are appropriate.
- Maintainable and easy to extend.

Library headers may depend on one another using paths relative to `library/`. The `compile.sh` script resolves these dependencies when creating a single-file submission.

## Problem Tracker

The [`repository/`](repository/) directory contains a local Node.js application for browsing the generated problem library and tracking CP progress. It is intended to grow into a training-management tool for:

- Searching and organizing solved and planned problems.
- Recording ratings, topics, dates, resolution time, and whether help was needed.
- Linking to problem statements and repository solutions.
- Scheduling problems for later review and memory reinforcement.
- Producing statistics that help identify useful topics and training priorities.

Run it locally with:

```sh
cd repository
npm start
```

Then open <http://localhost:3000>. More details are available in [`repository/README.md`](repository/README.md).

The application should remain simple, responsive, maintainable, and consistent with its solarized-beige visual theme. Preserve existing problem data when adding features.

Before pushing changes, install the app dependencies from `repository/` with `npm install`. This configures the Husky pre-push hook, which runs `scripts/refresh_data.py` and commits changes to `data/problem-library.json` when the generated problem data has changed.

## Configuration and Snippets

The [`config/`](config/) directory contains the Vim setup and C++ snippets used during contests. The snippets file is intentionally limited to short, frequently used constructs; complex algorithms belong in the library instead.

When modifying snippets:

1. Keep the snippets alphabetically ordered.
2. Update the listing in the first snippet.
3. Keep the configuration compatible with the setup performed by `scripts/config.sh`.

## Protected Solutions

The `learning/` and `training/` directories contain exercises and solutions resolved by the owner. Do not modify, reformat, rename, delete, or generate files in those directories unless the owner explicitly requests a specific change.

## Contributing

For changes to tools or applications:

1. Inspect existing patterns before introducing new abstractions.
2. Keep changes focused and cross-platform where applicable.
3. Preserve existing behavior and data.
4. Run the smallest relevant build, test, or validation command.
5. Update related documentation when usage changes.
