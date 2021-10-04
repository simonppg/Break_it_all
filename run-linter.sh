#!/bin/bash
set -x # echo commands

SCRIPT_PATH="${0%/*}"

# No matter where you are, the script always runs in this directory
cd $SCRIPT_PATH

docker run \
    -e RUN_LOCAL=ture \
    -v $PWD:/tmp/lint \
    github/super-linter
