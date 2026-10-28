#!/bin/bash

# Use first argument as directory, or current directory if not provided
DIR="${1:-.}"

# Check if the directory exists
if [ ! -d "$DIR" ]; then
    echo "Error: '$DIR' is not a valid directory."
    exit 1
fi

# Count .cpp files (non-recursive), ignoring any name that contains "_"
COUNT=$(find "$DIR" -maxdepth 1 -type f -name "*.cpp" ! -name "*_*" | wc -l)

echo "Number of problems in '$DIR': $COUNT"
