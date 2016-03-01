#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Lexeme.hpp"

#include "FactoryTest/GateFactory.hpp"
#include "FactoryTest/AndGate.hpp"

#include <functional>

using namespace std;

int main() {
    FactoryTest::AndGate("AND");

    FactoryTest::Gate* gate = FactoryTest::GateFactory::create("AND");

    CircuitParsing::Stage1Lexer appels("/home/mafn/School/OOPatronen/Practicum/Assignment/circuit1.txt");

    for(CircuitParsing::Lexeme lexeme : appels.output) {
        cout << "<" << lexeme.type << " value=" << lexeme.value << ">" << endl;
    }

    return 0;
}