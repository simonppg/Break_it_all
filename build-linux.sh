#!/bin/bash
set -x # echo commands

BUILD_DIR=linux-build

# Delete folder if exist
if [ -d "$BUILD_DIR" ]; then rm -Rf $BUILD_DIR; fi

# Create folder, move inside, build and run
mkdir -pv $BUILD_DIR && cd $BUILD_DIR && cmake .. && make run
