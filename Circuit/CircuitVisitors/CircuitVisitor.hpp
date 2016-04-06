//
// Created by mafn on 4/5/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUITVISITOR_HPP
#define OOPA_CIRCUITSIM_CIRCUITVISITOR_HPP

#include <string>

namespace Circuit {
  class Circuit;
}

namespace CircuitVisitors {
  using std::string;

  class CircuitVisitor {
  public:
      string name;

      virtual void visit(Circuit::Circuit& elem)=0;
  };
}


#endif //OOPA_CIRCUITSIM_CIRCUITVISITOR_HPP
