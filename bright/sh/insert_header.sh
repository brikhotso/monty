#!/bin/bash

# Loop through all .c files in the current directory
for file in *.c; do
    # Check if the file is a regular file
    if [ -f "$file" ]; then
        # Insert the line "include "monty.h"" at the beginning of each file
        sed -i '1i#include "monty.h"' "$file"
        echo "Inserted in $file"
    fi
done
