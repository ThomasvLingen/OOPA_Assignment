//
// Created by mafn on 4/7/16.
//

#ifndef OOPA_CIRCUITSIM_XORGATE_HPP
#define OOPA_CIRCUITSIM_XORGATE_HPP


#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Gate.hpp"
#include "CircuitUtility/Constructor.hpp"

namespace Circuit {
  using std::string;

  class XorGate : public Gate {
  public:
      XorGate(string name);
      XorGate(int id);
      ~XorGate();

      virtual bool evaluateOutput();
  };

  extern XorGate Assign_OrGate;
}


#endif //OOPA_CIRCUITSIM_XORGATE_HPP
