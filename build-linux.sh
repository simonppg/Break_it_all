#!/bin/bash
set -x # echo commands

SCRIPT_PATH="${0%/*}"

# No matter where you are, the script always runs in this directory
cd "$SCRIPT_PATH" || exit 1

BUILD_DIR=linux-build

# Delete folder if exist
if [ -d "$BUILD_DIR" ]; then rm -Rf $BUILD_DIR; fi

# Create folder, move inside, build and run
mkdir -pv $BUILD_DIR && cd $BUILD_DIR && cmake .. -DCMD_ARGS="0" -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_CXX_FLAGS="-isystem /usr/include/c++/11/ -isystem /usr/include/x86_64-linux-gnu/c++/11/" && make run

# NOTE: tell cmake to export compile commands and make the syslink is not really needed
# I use it to help the SLP (Server Language Protocol) to find the included headers files
# for more info look on this links:
# https://github.com/clangd/coc-clangd and https://clangd.llvm.org/installation.html#project-setup
ln -sf $BUILD_DIR/compile_commands.json ../compile_commands.json
