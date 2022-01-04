#!/bin/bash
set -e # Exit with nonzero exit code if anything fails

# Build the documentation from the MAIN_BRANCH or DEV_BRANCH
# and push it to TARGET_BRANCH.
MAIN_BRANCH="main"
TARGET_BRANCH="gh-pages"

mkdir out

# Build the Sphinx documentation
cd Docs
make html
cd ../

mkdir -p out/docs/
mv Docs/build/html/* out/docs
