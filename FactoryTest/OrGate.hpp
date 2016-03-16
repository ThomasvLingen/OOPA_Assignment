//
// Created by mafn on 3/1/16.
//

#ifndef OOPA_CIRCUITSIM_ORGATE_HPP
#define OOPA_CIRCUITSIM_ORGATE_HPP

#include "Gate.hpp"

namespace FactoryTest {
  class OrGate : public Gate {
  public:
      OrGate(string type);
      OrGate();
      ~OrGate();
  };

  OrGate* orConstructor();
  extern OrGate Assign_OrGate;
}


#endif //OOPA_CIRCUITSIM_ORGATE_HPP
