#include <iostream>
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

    try {
        parser.oC_Cypher();
        std::cout << "Query is valid!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Query is invalid!" << std::endl;
    }

    return 0;
}
