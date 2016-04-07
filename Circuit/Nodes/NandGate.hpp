//
// Created by mafn on 4/7/16.
//

#ifndef OOPA_CIRCUITSIM_NANDGATE_HPP
#define OOPA_CIRCUITSIM_NANDGATE_HPP


#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Gate.hpp"
#include "CircuitUtility/Constructor.hpp"

namespace Circuit {
  using std::string;

  class NandGate : public Gate {
  public:
      NandGate(string name);
      NandGate(int id);
      ~NandGate();

      virtual bool evaluateOutput();
  };

  extern NandGate Assign_NandGate;
}


#endif //OOPA_CIRCUITSIM_NANDGATE_HPP
