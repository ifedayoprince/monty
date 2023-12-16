#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Error: Please provide the directory path as a command-line argument."
    exit 1
fi

# Set the directory containing the scripts
script_directory="alx_tests/$1"

# Check if the directory exists
if [ ! -d "$script_directory" ]; then
    echo "Error: The specified directory does not exist."
    exit 1
fi

# Change to the script directory
cd "$script_directory" || exit 1

# Get a list of executable scripts in the directory
scripts=$(find . -type f -iname "*.sh" -executable)

# Check if there are no scripts to run
if [ -z "$scripts" ]; then
    echo "No executable scripts found in the specified directory."
    exit 0
fi

# Run each script one after another
for script in $scripts; do
    echo "Running script: $script"
    ./"$script"
    echo "--------------------------------------"
done
