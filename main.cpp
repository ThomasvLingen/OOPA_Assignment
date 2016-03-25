#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/CircuitParser.hpp"
#include "Circuit/Nodes/AndGate.hpp"
#include "Circuit/Nodes/InputHigh.hpp"

using namespace std;

int main() {
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

    Circuit::AndGate i_gate1("Input AND 1");
    Circuit::AndGate i_gate2("Input AND 2");
    Circuit::AndGate top_gate("top AND");

    Circuit::InputHigh i1("input 1");
    Circuit::InputHigh i2("input 2");
    Circuit::InputHigh i3("input 3");
    Circuit::InputHigh i4("input 4");

    i_gate1.addEdge(&i1);
    i_gate1.addEdge(&i2);
    i_gate2.addEdge(&i3);
    i_gate2.addEdge(&i4);
    top_gate.addEdge(&i_gate1);
    top_gate.addEdge(&i_gate2);

    cout << top_gate.output << " " << top_gate.evaluated << endl;

    i1.evaluate();
    i2.evaluate();
    i3.evaluate();
    i4.evaluate();


    cout << top_gate.output << " " << top_gate.evaluated << endl;

    return 0;
}