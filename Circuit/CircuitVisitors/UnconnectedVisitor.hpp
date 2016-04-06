//
// Created by mafn on 4/6/16.
//

#ifndef OOPA_CIRCUITSIM_UNCONNECTEDVISITOR_HPP
#define OOPA_CIRCUITSIM_UNCONNECTEDVISITOR_HPP

#include <string>

#include "Circuit/CircuitVisitors/CircuitVisitor.hpp"
#include "Circuit/Circuit.hpp"
#include "Circuit/Nodes/Node.hpp"

namespace CircuitVisitors {
  using std::string;

  class UnconnectedVisitor : public CircuitVisitor {
  public:
      UnconnectedVisitor();

      void visit(Circuit::Circuit &elem);
  };

}


#endif //OOPA_CIRCUITSIM_UNCONNECTEDVISITOR_HPP
