#include <iostream>
#include <cpr/cpr.h>
#include <antlr4-runtime.h>
#include "antlr/CypherLexer.h"
#include "antlr/CypherParser.h"

int main() {
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
    }

    // After getting the query from the user:
    // cpr::Response r = cpr::Post(cpr::Url{"http://localhost:8080/query"},
    //                             cpr::Body{inputQuery},
    //                             cpr::Header{{"Content-Type", "text/plain"}});
                            
    // if (r.status_code == 200) {
    //     std::cout << "Server Response: " << r.text << std::endl;
    // } else {
    //     std::cerr << "Failed to connect to server or server error." << std::endl;
    // }
    
    // return 0;
}
