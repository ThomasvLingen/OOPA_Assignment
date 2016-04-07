#include <iostream>
#include "Circuit/CircuitVisitors/CircuitStatsVisitor.hpp"
#include "Circuit/CircuitVisitors/UnconnectedVisitor.hpp"
#include "Circuit/CircuitVisitors/CircuitFeedbackVisitor.hpp"

#include "Circuit/CircuitSimulator.hpp"

using namespace std;

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
