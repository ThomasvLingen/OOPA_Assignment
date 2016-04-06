//
// Created by mafn on 4/6/16.
//

#include "UnconnectedVisitor.hpp"

namespace CircuitVisitors {
  UnconnectedVisitor::UnconnectedVisitor() {}

  void UnconnectedVisitor::visit(Circuit::Circuit &elem) {
      for (Circuit::Node* node : elem.circuit) {
          if (node->inputEdges.size() != node->requiredInputs) {
              throw "Node '" + node->name + "' does not have all it's inputs connected";
          }
      }
  }
}