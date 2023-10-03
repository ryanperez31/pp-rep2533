#include <iostream>
#include "../../lib/antlr4-runtime.h"
#include "CypherLexer.h"
#include "CypherParser.h"

int main() {
    antlr4::ANTLRInputStream input("MATCH (n) RETURN n;");
    CypherLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    CypherParser parser(&tokens);

    antlr4::tree::ParseTree* tree = parser.oC_Cypher();
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
}