#!/bin/bash

# Get the list of unique contributors from Git history
contributors=$(git log --format="%aN <%aE>" | sort -u)

# Create or truncate the AUTHORS file
> AUTHORS

# Append formatted contributors to the AUTHORS file
for contributor in $contributors; do
  echo "$contributor" >> AUTHORS
done

echo "Authors list has been generated and saved to AUTHORS file."

