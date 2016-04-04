//
// Created by mafn on 3/25/2016.
//

#ifndef OOPA_CIRCUITSIM_ANDGATE_HPP
#define OOPA_CIRCUITSIM_ANDGATE_HPP

#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Gate.hpp"
#include "CircuitUtility/Constructor.hpp"


namespace Circuit {
  using std::string;

  class AndGate : public Gate {
  public:
      AndGate(string name);
      AndGate(int id);
      ~AndGate();

      virtual bool evaluateOutput();
  };

  extern AndGate Assign_AndGate;
}


#endif //OOPA_CIRCUITSIM_ANDGATE_HPP
