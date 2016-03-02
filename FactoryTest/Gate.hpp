//
// Created by mafn on 3/1/16.
//

#ifndef OOPA_CIRCUITSIM_GATE_HPP
#define OOPA_CIRCUITSIM_GATE_HPP

#include <string>

#include "GateFactory.hpp"

namespace FactoryTest {
  using namespace std;

  class Gate {
  public:
      string type;
      Gate(string type);
      Gate();
      virtual ~Gate();
  private:
  };
}



#endif //OOPA_CIRCUITSIM_GATE_HPP