#!/usr/bin/env bash

pushd $(git rev-parse --show-toplevel)

set -e

declare -r FILTER=-build/include_subdir,-runtime/references

grep -E -r --include=\*.{cpp,h,hpp} -L 'cmake-build-debug' ./src/* ./tests/* | xargs python3 -m cpplint --linelength=120 --filter=$FILTER --output=vs7

popd