#!/bin/bash
set -x # echo commands

SCRIPT_PATH="${0%/*}"

# No matter where you are, the script always runs in this directory
cd $SCRIPT_PATH || exit

BUILD_DIR=test-build
BUILD_TYPE=Release

# Delete folder if exist
if [ -d "$BUILD_DIR" ]; then rm -Rf $BUILD_DIR; fi

# Create folder, move inside, build and run
mkdir -pv $BUILD_DIR && cmake -B $BUILD_DIR -DCMAKE_BUILD_TYPE=$BUILD_TYPE && cmake --build $BUILD_DIR --config $BUILD_TYPE && cd $BUILD_DIR && ctest -C $BUILD_TYPE
