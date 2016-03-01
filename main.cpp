#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Lexeme.hpp"

#include "FactoryTest/GateFactory.hpp"
#include "FactoryTest/AndGate.hpp"
#include "FactoryTest/OrGate.hpp"

#include <functional>

using namespace std;

int main() {
    FactoryTest::AndGate("AND");
    FactoryTest::OrGate("OR");

    FactoryTest::Gate* gate = FactoryTest::GateFactory::create("AND");
    FactoryTest::Gate* gate2 = FactoryTest::GateFactory::create("OR");

    CircuitParsing::Stage1Lexer appels("/home/mafn/School/OOPatronen/Practicum/Assignment/circuit1.txt");

    for(CircuitParsing::Lexeme lexeme : appels.output) {
        cout << "<" << lexeme.type << " value=" << lexeme.value << ">" << endl;
    }

    return 0;
}