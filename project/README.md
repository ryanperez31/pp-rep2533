Run the script "setup.sh" first
    Step 1: In the project directory run the command "chmod +x setup.sh"
            - run the command "./setup.sh"

Then run the Go server by doing the following:
    Step 2: Naviagte to server folder in termial
            Run the command "go run server.go -uri "bolt://localhost:7687" -username "your_username" -password "your_password""
            - replace "your_username" and "your_password" with your Neo4j credentials

Then run the client code in the "main.cpp" file
    Step 3: Navigate to the antlr client folder
            -project/src/client
            Run the command "g++ -std=c++17 main.cpp antlr/CypherLexer.cpp antlr/CypherParser.cpp -I/usr/local/include/antlr4-runtime -L/usr/local/lib -o client_app -lantlr4-runtime -lcpr"
            The run the client execultible by running the command "./client_app"

Then run the OCaml visualizer code in the "visualizer.ml" file
    Step 4: The run the client execultible by running the command "./client_app"


        then run "ocamlfind ocamlc -o visualizer -package yojson -linkpkg visualizer.ml"

        to run code it's ./visualizer

Then run the Smalltalk visualizer code in the pharro launcher
    Step 5: Open Smalltalk visualizer in project/src/visualizer/Smalltalk
            -run this code in playground in pharro launch
            | visualizer |
            visualizer := GraphVisualizer new.
            visualizer visualizeGraphFromFile: '/Users/ryanperez/Documents/GitHub/pp-rep2533/project/src/data/test.json'.
     replace path with path to the response.json file in project/src/data/response.json

    | visualizer |
    visualizer := GraphVisualizer new.
    visualizer visualizeGraphFromFile: '/Users/ryanperez/Documents/GitHub/pp-rep2533/project/src/data/test.json'.


FOR TESTING:
-You can send queries in the termial after launching ./client_app and the reponse will be outputted to the terminal
-To add additional test queries for go server add queries to the array below in server.go:
queries := []string{
		"MATCH (n) RETURN n LIMIT 5",
		"MATCH (n:Person) RETURN n.name LIMIT 5",
	}
-To visit queries test queries from go to http://localhost:8080/preselected-queries

