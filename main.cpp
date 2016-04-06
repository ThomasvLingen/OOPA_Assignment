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

int main(int argc, char* argv[]) {
    Circuit::CircuitSimulator sim(
        "/home/mafn/School/OOPatronen/Practicum/Assignment/circuit4.txt",
        {
                new CircuitVisitors::UnconnectedVisitor(),
                new CircuitVisitors::CircuitFeedbackVisitor(),
                new CircuitVisitors::CircuitStatsVisitor()
        }
    );

    return 0;
}