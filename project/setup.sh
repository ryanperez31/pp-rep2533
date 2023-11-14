#!/bin/bash

# Define directories relative to the script location
SCRIPT_DIR=$(dirname "$0")
OCAML_DIR="$SCRIPT_DIR/src/visualizer/OCaml"
OPAM_DIR="$OCAML_DIR/opam"

# Create the OCaml and OPAM directories if they don't exist
mkdir -p "$OCAML_DIR"
mkdir -p "$OPAM_DIR"

# Check if OPAM is installed
if ! command -v opam &> /dev/null
then
    echo "OPAM could not be found, installing..."
    bash -c "sh <(curl -fsSL https://raw.githubusercontent.com/ocaml/opam/master/shell/install.sh)"
else
    echo "OPAM is already installed."
fi

# Initialize OPAM in the specific directory
echo "Initializing OPAM in $OPAM_DIR..."
opam init --root="$OPAM_DIR" --disable-sandboxing -y

# Set the OPAM environment for the current session
eval $(opam env --root="$OPAM_DIR")

# Create a local switch for OCaml in the OCaml directory, letting OPAM choose the OCaml version
echo "Creating a local switch for OCaml in $OCAML_DIR..."
opam switch create "$OCAML_DIR" --root="$OPAM_DIR"

# Install Yojson and OCamlFind
echo "Installing Yojson and OCamlFind..."
opam install yojson ocamlfind -y

# Directory where ANTLR will be set up
ANTLR_DIR="$HOME/antlr-setup"

# Directory where Neo4j will be set up
NEO4J_DIR="$HOME/neo4j-setup"

# Directory where CPR will be set up
CPR_DIR="$HOME/cpr-setup"

# Ensure the ANTLR, Neo4j, and CPR setup directories exist
mkdir -p $ANTLR_DIR
mkdir -p $NEO4J_DIR
mkdir -p $CPR_DIR

# Step 1: Clone the specific ANTLR4 C++ runtime branch
echo "Cloning ANTLR4 C++ runtime from 'dev' branch..."
cd $ANTLR_DIR
git clone -b dev https://github.com/antlr/antlr4.git

# Step 2: Build and install the ANTLR4 C++ runtime
echo "Building and installing ANTLR4 C++ runtime..."
ANTLR_SRC_DIR="$ANTLR_DIR/antlr4/runtime/Cpp"
mkdir -p $ANTLR_SRC_DIR/build
cd $ANTLR_SRC_DIR/build

# Step 3: Use CMake to configure and build the ANTLR4 C++ runtime
cmake .. -DWITH_DEMO=False -DANTLR4_INSTALL=system
make -j4
sudo make install

# If you've reached here, ANTLR runtime should be installed system-wide
echo "ANTLR4 C++ runtime setup complete."

# Step 4: Clone, build, and install the CPR library
echo "Setting up CPR library..."
cd $CPR_DIR
git clone --recursive https://github.com/whoshuu/cpr.git

# Step 5: Navigate to the cloned directory and build
cd cpr
mkdir build && cd build
cmake ..
make -j4
sudo make install

echo "CPR setup complete."

# Step 3: Download and setup Neo4j
NEO4J_TAR_URL="https://neo4j.com/artifact.php?name=neo4j-community-5.12.0-unix.tar.gz"

if [ ! -d "$NEO4J_DIR/neo4j-community-5.12.0" ]; then
    echo "Downloading Neo4j..."
    cd $NEO4J_DIR
    curl -L -O $NEO4J_TAR_URL || { echo "Failed to download Neo4j"; exit 1; }

    # Rename the file in case it's named artifact.php
    if [ -f "artifact.php" ]; then
        mv artifact.php neo4j-community-5.12.0-unix.tar.gz
    fi

    echo "Extracting Neo4j tarball..."
    tar zxf neo4j-community-5.12.0-unix.tar.gz

    echo "Accepting Neo4j license..."
    export NEO4J_ACCEPT_LICENSE_AGREEMENT=yes

    echo "Starting Neo4j in the background..."
    $NEO4J_DIR/neo4j-community-5.12.0/bin/neo4j start
else
    echo "Neo4j seems to be set up already. Skipping this step."
    $NEO4J_DIR/neo4j-community-5.12.0/bin/neo4j start
fi

# Wait for Neo4j to start up
echo "Waiting for Neo4j to start..."
sleep 15

# Check if Neo4j is up and running
echo "Checking if Neo4j is running..."
curl_response=$(curl --silent --write-out "HTTPSTATUS:%{http_code}" -u neo4j:neo4j http://localhost:7474/db/data/)
http_status=$(echo $curl_response | tr -d '\n' | sed -e 's/.*HTTPSTATUS://')

if [ $http_status -eq 401 ]; then
    echo "Neo4j is up and running! Note: You might need to change the default password."
    xdg-open http://localhost:7474
else
    echo "Something went wrong. Couldn't confirm if Neo4j is running."
fi

# Step 6: Download nlohmann/json library used to parse JSON in c++
# echo "Downloading nlohmann/json library..."
# JSON_DIR="$HOME/json-setup"
# mkdir -p $JSON_DIR
# cd $JSON_DIR
# curl -L -O https://raw.githubusercontent.com/nlohmann/json/master/single_include/nlohmann/json.hpp

# if [ -f "json.hpp" ]; then
#     echo "nlohmann/json library setup complete."
# else
#     echo "Failed to download nlohmann/json library."
# fi

# Step 4: Open Cypher Shell
echo "Opening Cypher Shell..."
$NEO4J_DIR/neo4j-community-5.12.0/bin/cypher-shell

# Return to the original directory
cd -
