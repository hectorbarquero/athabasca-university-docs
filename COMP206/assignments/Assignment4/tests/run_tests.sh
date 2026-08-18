#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")/.."
CXX="${CXX:-g++}"

"$CXX" -std=c++17 -Wall -Wextra -pedantic \
  main.cpp Game.cpp Control.cpp Action.cpp Location.cpp Item.cpp \
  Character.cpp Inventory.cpp TextUtils.cpp -o Wonderland

./Wonderland --seed 1 --no-random < tests/win_commands.txt > tests/win_output.txt
grep -q "All four treasures are safe" tests/win_output.txt
grep -q "You win" tests/win_output.txt
grep -q "Quiet Garden" tests/win_output.txt

./Wonderland --seed 1 --no-random < tests/parser_commands.txt > tests/parser_output.txt
grep -q "Riverbank" tests/parser_output.txt
grep -q "You are carrying nothing" tests/parser_output.txt
grep -q "You cannot go in that direction" tests/parser_output.txt
grep -q "I do not understand that command" tests/parser_output.txt
grep -q "Taken: White Rabbit's Fan" tests/parser_output.txt
grep -q "Dropped: White Rabbit's Fan" tests/parser_output.txt

if ./Wonderland --data tests/missing-data > tests/missing_output.txt 2>&1; then
  echo "Missing-data test unexpectedly succeeded." >&2
  exit 1
fi
grep -q "Game data error" tests/missing_output.txt

echo "All automated tests passed."
