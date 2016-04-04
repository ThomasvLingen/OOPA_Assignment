//
// Created by mafn on 4/4/16.
//

#ifndef OOPA_CIRCUITSIM_NOTGATE_HPP
#define OOPA_CIRCUITSIM_NOTGATE_HPP


#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Gate.hpp"
#include "CircuitUtility/Constructor.hpp"


namespace Circuit {
  using std::string;

  class NotGate : public Gate {
  public:
      NotGate(string name);
      NotGate(int id);
      ~NotGate();

      virtual bool evaluateOutput();
  };

  extern NotGate Assign_NotGate;
}


#endif //OOPA_CIRCUITSIM_NOTGATE_HPP
