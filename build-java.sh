#!/usr/bin/env bash
# Compiles every Java solution with its Main.java test driver and runs it.
set -uo pipefail
cd "$(dirname "$0")"

failures=0

for dir in problems/*/; do
    dir="${dir%/}"
    [[ -f "$dir/Solution.java" && -f "$dir/Main.java" ]] || continue

    problem="$(basename "$dir")"
    out="build/java/$problem"
    echo "=== $problem"
    rm -rf "$out"

    if javac -Xlint:all -Werror -d "$out" "$dir/Solution.java" "$dir/Main.java"; then
        java -cp "$out" Main || failures=$((failures + 1))
    else
        failures=$((failures + 1))
    fi
done

echo
if (( failures > 0 )); then
    echo "$failures problem(s) failed."
    exit 1
fi
echo "All Java solutions passed."
