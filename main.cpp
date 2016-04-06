#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/CircuitParser.hpp"
#include "Circuit/NodeFactory.hpp"
#include "Circuit/Nodes/Node.hpp"
#include "Circuit/Circuit.hpp"
#include "Circuit/CircuitVisitors/CircuitStatsVisitor.hpp"
#include "Circuit/CircuitVisitors/UnconnectedVisitor.hpp"
#include "Circuit/CircuitVisitors/CircuitFeedbackVisitor.hpp"

#include "Circuit/CircuitSimulator.hpp"

using namespace std;
using Circuit::NodeFactory;
using Circuit::nodeType;

void printUsage();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 0;
    }

    Circuit::CircuitSimulator sim(
        argv[1],
        {
                new CircuitVisitors::UnconnectedVisitor(),
                new CircuitVisitors::CircuitFeedbackVisitor(),
                new CircuitVisitors::CircuitStatsVisitor()
        }
    );

    return 0;
}

void printUsage() {
    cout << "Usage: OOPA_CircuitSim [CIRCUITFILE]" << endl;
}
