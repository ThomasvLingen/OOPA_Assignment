//
// Created by mafn on 4/5/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUITVISITOR_HPP
#define OOPA_CIRCUITSIM_CIRCUITVISITOR_HPP

namespace Circuit {
  class Circuit;
}

namespace CircuitVisitors {
  class CircuitVisitor {
  public:
      virtual void visit(Circuit::Circuit& elem)=0;
  };
}


#endif //OOPA_CIRCUITSIM_CIRCUITVISITOR_HPP
