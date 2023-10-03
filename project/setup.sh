#!/bin/bash

# Directory where everything related to ANTLR will be set up
ANTLR_DIR="$HOME/antlr-setup"

# Ensure the ANTLR setup directory exists
mkdir -p $ANTLR_DIR

# Step 1: Clone the specific ANTLR4 C++ runtime branch
echo "Cloning ANTLR4 C++ runtime from 'dev' branch..."
cd $ANTLR_DIR
git clone -b dev https://github.com/antlr/antlr4.git

# Step 2: Build and install the ANTLR4 C++ runtime
echo "Building and installing ANTLR4 C++ runtime..."
ANTLR_SRC_DIR="$ANTLR_DIR/antlr4/runtime/Cpp"
mkdir -p $ANTLR_SRC_DIR/build
cd $ANTLR_SRC_DIR/build

# Use CMake to configure and build the ANTLR4 C++ runtime
cmake .. -DWITH_DEMO=False -DANTLR4_INSTALL=system
make -j4
sudo make install

# If you've reached here, ANTLR runtime should be installed system-wide
echo "ANTLR4 C++ runtime setup complete."

# Return to the original directory
cd -
