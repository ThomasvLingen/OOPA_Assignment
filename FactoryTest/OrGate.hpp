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
  private:
      static OrGate m_OrGate;
  };

  OrGate* orConstructor();
}


#endif //OOPA_CIRCUITSIM_ORGATE_HPP
