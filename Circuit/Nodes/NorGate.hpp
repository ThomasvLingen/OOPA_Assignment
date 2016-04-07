//
// Created by mafn on 4/7/16.
//

#ifndef OOPA_CIRCUITSIM_NORGATE_HPP
#define OOPA_CIRCUITSIM_NORGATE_HPP


#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Gate.hpp"
#include "CircuitUtility/Constructor.hpp"

namespace Circuit {
  using std::string;

  class NorGate : public Gate {
  public:
      NorGate(string name);
      NorGate(int id);
      ~NorGate();

      virtual bool evaluateOutput();
  };

  extern NorGate Assign_NorGate;
}


#endif //OOPA_CIRCUITSIM_NORGATE_HPP
