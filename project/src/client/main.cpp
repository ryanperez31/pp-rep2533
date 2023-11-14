#include <iostream>
#include <fstream>
#include <cpr/cpr.h>
#include <cpr/util.h>  // for urlEncode
#include <unistd.h>  // For getcwd
#include <limits.h>  // For PATH_MAX
#include <regex>
#include <string>
//#include <nlohmann/json.hpp>
#include <cstdlib>
#include <antlr4-runtime.h>
#include "antlr/CypherLexer.h"
#include "antlr/CypherParser.h"

int main() {
    while(1){
        std::string inputQuery;

        std::cout << "Please enter a Cypher query: ";
        std::getline(std::cin, inputQuery);

        antlr4::ANTLRInputStream input(inputQuery);
        CypherLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        CypherParser parser(&tokens);

        parser.removeErrorListeners(); // remove the default error listener
        antlr4::ConsoleErrorListener consoleErrorListener; // for printing to std::cerr
        parser.addErrorListener(&consoleErrorListener); // add our error listener

        auto tree = parser.oC_Cypher();

        if (parser.getNumberOfSyntaxErrors() == 0) {
            std::cout << "Query is valid!" << std::endl;
        } else {
            std::cerr << "Query is invalid!" << std::endl;
            return 1;  // Exit early if query is invalid
        }

        // URL encode the query
        std::string encodedQuery = cpr::util::urlEncode(inputQuery);

        // Send GET request with the query as a URL parameter
        cpr::Response r = cpr::Get(cpr::Url{"http://localhost:8080/custom-query?query=" + encodedQuery});

        if (r.status_code == 200) {
            std::cout << "Server Response: " << r.text << std::endl;

            //For debugging purposes
            // char cwd[PATH_MAX];
            // if (getcwd(cwd, sizeof(cwd)) != NULL) {
            //     std::cout << "Current working directory: " << cwd << std::endl;
            // } else {
            //     std::cerr << "getcwd() error" << std::endl;
            // }

            // After receiving the response from the server
            std::ofstream txtFile("../data/response.txt");
            if (txtFile.is_open()) {
                txtFile << r.text;
                txtFile.close();
                std::cout << "Response saved to ../data/response.txt" << std::endl;
                system("python3 parseJSON.py"); //call python script to correctly parse response for JSON file
            } else {
                std::cerr << "Unable to open file to write response." << std::endl;
            }
        } else {
            std::cerr << "Failed to connect to server or server error. Status code: " << r.status_code << std::endl;
        }                     
    }
    return 0;
}
