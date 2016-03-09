#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/Lexeme.hpp"

#include "FactoryTest/GateFactory.hpp"
#include "FactoryTest/AndGate.hpp"
#include "FactoryTest/OrGate.hpp"

using namespace std;

int main() {
    FactoryTest::AndGate("AND");
    FactoryTest::OrGate("OR");

    FactoryTest::Gate* gate = FactoryTest::GateFactory::create("AND");
    FactoryTest::Gate* gate2 = FactoryTest::GateFactory::create("OR");

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