//
// Created by mafn on 4/5/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUITSTATSVISITOR_HPP
#define OOPA_CIRCUITSIM_CIRCUITSTATSVISITOR_HPP

#include <iostream>

#include "Circuit/CircuitVisitors/CircuitVisitor.hpp"
#include "Circuit/Circuit.hpp"
#include "Circuit/Nodes/Node.hpp"

namespace CircuitVisitors {
  using std::cout;
  using std::endl;

  class CircuitStatsVisitor : public CircuitVisitor{
  public:
      CircuitStatsVisitor();

      void visit(Circuit::Circuit& elem);
      void listInputs(Circuit::Circuit& elem);
      void listOutputs(Circuit::Circuit& elem);
      void listNode(Circuit::Node* node);
  };
}


#endif //OOPA_CIRCUITSIM_CIRCUITSTATSVISITOR_HPP
