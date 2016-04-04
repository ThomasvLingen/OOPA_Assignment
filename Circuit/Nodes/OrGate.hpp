//
// Created by mafn on 4/4/16.
//

#ifndef OOPA_CIRCUITSIM_ORGATE_HPP
#define OOPA_CIRCUITSIM_ORGATE_HPP

#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Gate.hpp"
#include "CircuitUtility/Constructor.hpp"

namespace Circuit {
  using std::string;

  class OrGate : public Gate {
  public:
      OrGate(string name);
      OrGate(int id);
      ~OrGate();

      virtual bool evaluateOutput();
  };

  extern OrGate Assign_OrGate;
}


#endif //OOPA_CIRCUITSIM_ORGATE_HPP
