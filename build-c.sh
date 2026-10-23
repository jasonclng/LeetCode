#!/usr/bin/env bash
# Builds every C solution with CMake and runs its main.c test driver.
set -euo pipefail
cd "$(dirname "$0")"

cmake -S . -B build/c -DCMAKE_BUILD_TYPE=Release
cmake --build build/c --config Release
ctest --test-dir build/c -C Release --output-on-failure
