#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"

using namespace std;

int main() {
    // Lex the input file
    CircuitParsing::Stage1Lexer appels("/home/mafn/School/OOPatronen/Practicum/Assignment/circuit1.txt");

    // Print the results
    for(CircuitParsing::Lexeme lexeme : appels.output) {
        cout << "<" << lexeme.type << " value=" << lexeme.value << ">" << endl;
    }

    return 0;
}