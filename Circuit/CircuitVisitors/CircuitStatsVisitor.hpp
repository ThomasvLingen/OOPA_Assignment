//
// Created by mafn on 4/5/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUITSTATSVISITOR_HPP
#define OOPA_CIRCUITSIM_CIRCUITSTATSVISITOR_HPP

#include <iostream>

#include "Circuit/CircuitVisitors/CircuitVisitor.hpp"
#include "Circuit/Circuit.hpp"

namespace CircuitVisitors {
  using std::cout;
  using std::endl;

  class CircuitStatsVisitor : public CircuitVisitor{
  public:
      CircuitStatsVisitor();

      void visit(Circuit::Circuit& elem);
  };
}


#endif //OOPA_CIRCUITSIM_CIRCUITSTATSVISITOR_HPP
