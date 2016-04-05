//
// Created by mafn on 4/5/16.
//

#include "CircuitStatsVisitor.hpp"

namespace CircuitVisitors {
  CircuitStatsVisitor::CircuitStatsVisitor() {}

  void CircuitStatsVisitor::visit(Circuit::Circuit &elem) {
      cout << "== Circuit stats ==" << endl;
      cout << "- Node count: " << endl << "  " << elem.circuit.size() << endl;

      this->listInputs(elem);
      this->listOutputs(elem);
  }

  void CircuitStatsVisitor::listInputs(Circuit::Circuit &elem) {
      cout << "- Input nodes:" << endl;
      for (Circuit::Node* node : elem.inputs) {
          cout << "  ";
          this->listNode(node);
      }
  }

  void CircuitStatsVisitor::listOutputs(Circuit::Circuit &elem) {
      cout << "- Output nodes:" << endl;
      for (Circuit::Node* node : elem.outputs) {
          cout << "  ";
          this->listNode(node);
      }
  }

  void CircuitStatsVisitor::listNode(Circuit::Node *node) {
      cout << node->name << " - " << node->output << endl;
  }
}