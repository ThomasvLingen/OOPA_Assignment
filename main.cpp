#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"

using namespace std;

int main() {
    // Lex the input file
    cout << "[Stage 1 lexing] START" << endl;
    CircuitParsing::Stage1Lexer appels("/home/mafn/School/OOPatronen/Practicum/Assignment/circuit1.txt");
    cout << "[Stage 1 lexing] END" << endl;
    cout << "[Stage 2 lexing] START" << endl;
    CircuitParsing::Stage2Lexer peren(appels.output);
    cout << "[Stage 2 lexing] END" << endl;

    // Print the results
    for(CircuitParsing::Lexeme lexeme : peren.output) {
        cout << "<" << lexeme.type << " value=" << lexeme.value << ">" << endl;
    }

    return 0;
}