#!/bin/bash

set -e

BUILD_DIR=build
BIN_DIR=bin

mkdir -p $BUILD_DIR
mkdir -p $BIN_DIR

cd $BUILD_DIR

cmake ..
make -j$(nproc)

cp runtime-monitor ../$BIN_DIR/

echo "Installed to bin/runtime-monitor"