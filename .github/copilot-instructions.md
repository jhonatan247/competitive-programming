# Competitive Programming Repository Guidelines

## Repository Purpose

This repository captures and improves the owner's competitive programming (CP) training workflow. Prefer changes that make solving, practicing, reviewing, and competing more efficient while keeping the repository useful to other CP programmers.

The repository is intended to work on any computer with the required dependencies after running [`scripts/config.sh`](../scripts/config.sh). Preserve compatibility with WSL Ubuntu and macOS; avoid assumptions that only work on Windows or on one local machine.

## Protected Exercise Directories

- **Never read, modify, move, rename, delete, reformat, or generate files in `learning/` or `training/`.**
- Treat these directories as solved personal exercises and keep them completely untouched by Copilot.
- If a requested change appears to require touching either directory, stop and ask for explicit guidance before proceeding.

## Scripts

The [`scripts/`](../scripts/) directory contains utilities used while programming and competing. When changing a script:

- Optimize for a smooth competitive programming experience and fast feedback.
- Follow robust scripting practices: quote paths, validate inputs, use clear exit statuses, avoid unnecessary external dependencies, and preserve useful error messages.
- Keep behavior portable between WSL Ubuntu and macOS.
- Preserve executable permissions where applicable.
- Consider how scripts compose with one another, especially compilation, local testing, stress testing, validation, and submission workflows.
- Keep [`scripts/compile.sh`](../scripts/compile.sh) compatible with library includes and its generated single-file online-judge submission output.

## C++ Library

The [`library/`](../library/) directory is a C++-only competitive programming library. Library changes should provide general, reusable solutions that fit a broad range of problems.

- Keep implementations self-contained and usable with minimal setup.
- For classes and data structures, prefer clear object-oriented designs with encapsulated state and a small, self-explanatory public interface.
- Keep related state, operations, and invariants inside the primary class or structure; avoid scattering implementation logic into unrelated global functions.
- Favor maintainability and extensibility without sacrificing competitive-programming performance.
- Use appropriate complexity, standard C++ facilities, and safe, predictable behavior.
- Preserve the library's include convention: a library file may include another library file using a path relative to `library/`, for example `#include "algo/modular.h"`.
- Check that changes remain compatible with [`scripts/compile.sh`](../scripts/compile.sh), which can combine library dependencies into one file ready for an online judge.
- Do not add non-C++ implementations to this library.

## Configuration and Snippets

The [`config/`](../config/) directory contains Vim configuration and C++ snippets.

- Vim-related configuration should make the primary editor experience fluid, practical, and unobtrusive.
- Keep [`config/cpp.snippets`](../config/cpp.snippets) focused on short, frequently used C++ snippets. Do not put complex or long algorithms or data structures there.
- Keep snippets alphabetically ordered for quick lookup.
- The first snippet contains the complete snippet listing. Whenever a snippet is added or modified, update that listing and verify that the body remains alphabetically ordered.
- Preserve compatibility with the setup performed by [`scripts/config.sh`](../scripts/config.sh).

## Problem Tracker Web Project

The [`repository/`](../repository/) directory contains a Node.js application for tracking solved and planned problems. Its long-term purpose is to help organize CP training and optimize practice time by recording problem metadata, links, topics, help needed, solution history, review reminders, and useful statistics.

When working in this project:

- Design features around better training planning, spaced review, problem search, and actionable statistics.
- Keep the implementation simple, maintainable, and aligned with web development best practices.
- Ensure all features are responsive and usable on different screen sizes.
- Maintain the solarized-beige-like visual theme and its intended geek-oriented character.
- Avoid allowing individual files to grow too large. Once a file approaches 250 lines, consider splitting it into smaller components or modules; use a lightweight framework only if the project becomes complex enough to justify it.
- Preserve existing data and provide clear handling for invalid or missing problem information.

## General Change Practices

- Inspect the relevant existing code and reuse established patterns before introducing new ones.
- Make focused changes, preserve existing behavior, and update directly related documentation when behavior or usage changes.
- Prefer clear names and simple interfaces over cleverness.
- Test the smallest relevant surface for each change, including cross-platform script behavior when applicable.
