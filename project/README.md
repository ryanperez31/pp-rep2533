For Part 1 deiverables

Run the script "setup.sh" first
    Step 1: In the project directory run the command "chmod +x setup.sh"
    Step 2: Then run the command "./setup.sh"

Then run the client code in the "main.cpp" file
    Step 3: Navigate to the antlr client folder
            -project/src/client
    Step 4: Run the command "g++ -std=c++17 main.cpp antlr/CypherLexer.cpp antlr/CypherParser.cpp -I/usr/local/include/antlr4-runtime -L/usr/local/lib -o client_app -lantlr4-runtime"
    Step 5: The run the client execultible by running the command "./client_app"