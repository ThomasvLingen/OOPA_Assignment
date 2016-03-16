//
// Created by mafn on 3/1/16.
//

#ifndef OOPA_CIRCUITSIM_ANDGATE_HPP
#define OOPA_CIRCUITSIM_ANDGATE_HPP

#include "Gate.hpp"

#include "GateFactory.hpp"

namespace FactoryTest {
  class AndGate : public Gate {
  public:
      AndGate(string type);
      AndGate();
      ~AndGate();
  };

  AndGate* andConstructor();
  extern AndGate Assign_AndGate;
}


#endif //OOPA_CIRCUITSIM_ANDGATE_HPP
