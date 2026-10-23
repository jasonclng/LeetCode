@echo off
rem Builds every C solution with CMake and runs its main.c test driver.
setlocal
cd /d "%~dp0"

cmake -S . -B build\c -DCMAKE_BUILD_TYPE=Release || exit /b 1
cmake --build build\c --config Release || exit /b 1
ctest --test-dir build\c -C Release --output-on-failure || exit /b 1
