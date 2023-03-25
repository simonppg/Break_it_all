#!/bin/bash
set -x # echo commands

SCRIPT_PATH="${0%/*}"

# No matter where you are, the script always runs in this directory
cd "$SCRIPT_PATH" || exit 1

CPP_SRC_DIR=./app/src/main/cpp
REGEX='.*\.\(cpp\|hpp\)'

find $CPP_SRC_DIR -regex $REGEX -exec clang-format -i {} \;
find $CPP_SRC_DIR -regex $REGEX -exec cpplint {} \;
