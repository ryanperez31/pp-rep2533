#!/bin/bash

# Directory where ANTLR will be set up
ANTLR_DIR="$HOME/antlr-setup"

# Directory where Neo4j will be set up
NEO4J_DIR="$HOME/neo4j-setup"

# Ensure the ANTLR and Neo4j setup directories exist
mkdir -p $ANTLR_DIR
mkdir -p $NEO4J_DIR

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

# Step 3: Download and setup Neo4j
NEO4J_TAR_URL="https://neo4j.com/artifact.php?name=neo4j-community-5.12.0-unix.tar.gz"

if [ ! -d "$NEO4J_DIR" ]; then
    echo "Downloading Neo4j..."
    cd $NEO4J_DIR
    curl -O $NEO4J_TAR_URL

    echo "Extracting Neo4j tarball..."
    tar zxf neo4j-community-5.12.0-unix.tar.gz

    echo "Accepting Neo4j license..."
    export NEO4J_ACCEPT_LICENSE_AGREEMENT=yes

    echo "Starting Neo4j in the background..."
    $NEO4J_DIR/neo4j-community-5.12.0/bin/neo4j start
else
    echo "Neo4j seems to be set up already. Skipping this step."
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
    echo "Go to http://localhost:7474"
else
    echo "Something went wrong. Couldn't confirm if Neo4j is running."
fi

# Step 4: Open Cypher Shell
echo "Opening Cypher Shell..."
$NEO4J_DIR/neo4j-community-5.12.0/bin/cypher-shell

# Return to the original directory
cd -