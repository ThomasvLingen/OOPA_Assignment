#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/CircuitParser.hpp"
#include "Circuit/NodeFactory.hpp"
#include "Circuit/Nodes/Node.hpp"
#include "Circuit/Circuit.hpp"
#include "Circuit/CircuitVisitors/CircuitStatsVisitor.hpp"

using namespace std;
using Circuit::NodeFactory;
using Circuit::nodeType;

int main(int argc, char* argv[]) {
    // Lex the input file
    cout << "[Stage 1 lexing ] START" << endl;
    CircuitParsing::Stage1Lexer appels("/home/mafn/School/OOPatronen/Practicum/Assignment/circuit1.txt");
    cout << "[Stage 1 lexing ] END" << endl;

    cout << "[Stage 2 lexing ] START" << endl;
    CircuitParsing::Stage2Lexer peren(appels.output);
    cout << "[Stage 2 lexing ] END" << endl;

    cout << "[Stage 1 parsing] START" << endl;
    CircuitParsing::CircuitParser bananen(peren.output);
    cout << "[Stage 1 parsing] END" << endl;

    Circuit::Circuit zoodle(bananen.output);

    zoodle.evaluateCircuit();

    CircuitVisitors::CircuitStatsVisitor foo;
    zoodle.accept(foo);


    return 0;
}