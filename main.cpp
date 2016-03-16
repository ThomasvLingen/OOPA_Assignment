#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/Lexeme.hpp"

#include "FactoryTest/GateFactory.hpp"
#include "FactoryTest/AndGate.hpp"
#include "FactoryTest/OrGate.hpp"

using namespace std;

int main() {
    FactoryTest::Gate* gate = FactoryTest::GateFactory::create("AND");
    FactoryTest::Gate* gate2 = FactoryTest::GateFactory::create("OR");

    cout << gate->type << endl;
    cout << gate2->type << endl;

    return 0;
}