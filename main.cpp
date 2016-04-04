#include <iostream>
#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/CircuitParser.hpp"
#include "Circuit/NodeFactory.hpp"
#include "Circuit/Nodes/Node.hpp"
#include "Circuit/NodeTypes.hpp"

using namespace std;
using Circuit::NodeFactory;
using Circuit::nodeType;

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

    Circuit::Node* i_gate1  = NodeFactory::create(nodeType::AND, "Input AND");
    Circuit::Node* i_gate2  = NodeFactory::create(nodeType::OR, "Input OR");
    Circuit::Node* top_gate = NodeFactory::create(nodeType::AND, "Top AND");

    Circuit::Node* i1       = NodeFactory::create(nodeType::INPUT_HIGH, "input 1");
    Circuit::Node* i2       = NodeFactory::create(nodeType::INPUT_HIGH, "input 2");
    Circuit::Node* i3       = NodeFactory::create(nodeType::INPUT_LOW, "input 3");
    Circuit::Node* i4       = NodeFactory::create(nodeType::INPUT_HIGH, "input 4");

    i1->addEdge(i_gate1);
    i2->addEdge(i_gate1);
    i3->addEdge(i_gate2);
    i4->addEdge(i_gate2);
    i_gate1->addEdge(top_gate);
    i_gate2->addEdge(top_gate);

    cout << top_gate->output << " " << top_gate->evaluated << endl;
    i1->evaluate();
    cout << top_gate->output << " " << top_gate->evaluated << endl;
    i2->evaluate();
    cout << top_gate->output << " " << top_gate->evaluated << endl;
    i3->evaluate();
    cout << top_gate->output << " " << top_gate->evaluated << endl;
    i4->evaluate();
    cout << top_gate->output << " " << top_gate->evaluated << endl;

    Circuit::Node* not_inp = NodeFactory::create(nodeType::INPUT_LOW, "NOT input");
    Circuit::Node* not_gate = NodeFactory::create(nodeType::NOT, "Not Gate");
    Circuit::Node* not_probe = NodeFactory::create(nodeType::PROBE, "Not Probe");

    not_inp->addEdge(not_gate);
    not_gate->addEdge(not_probe);

    cout << "NOT gate: " << not_probe->output << " " << not_probe->evaluated << endl;
    not_inp->evaluate();
    cout << "NOT gate: " << not_probe->output << " " << not_probe->evaluated << endl;

    return 0;
}