//
// Created by mafn on 4/5/16.
//

#include "CircuitStatsVisitor.hpp"

namespace CircuitVisitors {
  CircuitStatsVisitor::CircuitStatsVisitor() {}

  void CircuitStatsVisitor::visit(Circuit::Circuit &elem) {
      cout << "== Circuit stats ==" << endl;
      cout << "Node count: " << elem.circuit.size() << endl;
  }
}