import unittest
from antlr4 import InputStream, CommonTokenStream
from antlr.CypherLexer import CypherLexer
from antlr.CypherParser import CypherParser

class TestCypherLexerParser(unittest.TestCase):
    def parse_query(self, query):
        input_stream = InputStream(query)
        lexer = CypherLexer(input_stream)
        token_stream = CommonTokenStream(lexer)
        parser = CypherParser(token_stream)
        return parser.oC_Cypher()

    def test_valid_queries(self):
        valid_queries = [
            "MATCH (n) RETURN n;",
            "CREATE (a:Person {name: 'Alice'}) RETURN a;",
            # Add more valid queries here
        ]
        
        for query in valid_queries:
            with self.subTest(query=query):
                try:
                    parse_tree = self.parse_query(query)
                    # Assert that parsing was successful (no exceptions)
                    self.assertIsNotNone(parse_tree)
                except Exception as e:
                    self.fail(f"Failed to parse query: {query}\nError: {str(e)}")

    def test_invalid_queries(self):
        invalid_queries = [
            "MATCH (n RETURN n;",
            "CREATE (a:Person {name 'Alice'}) RETURN a;",
            # Add more invalid queries here
        ]
        
        for query in invalid_queries:
            with self.subTest(query=query):
                with self.assertRaises(Exception):
                    self.parse_query(query)

if __name__ == "__main__":
    unittest.main()
