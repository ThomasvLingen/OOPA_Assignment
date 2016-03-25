//
// Created by mafn on 3/25/2016.
//

#ifndef OOPA_CIRCUITSIM_INPUTHIGH_HPP
#define OOPA_CIRCUITSIM_INPUTHIGH_HPP

#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Node.hpp"
#include "CircuitUtility/Constructor.hpp"

namespace Circuit {
  using std::string;

  class InputHigh : public Node {
  public:
      InputHigh(string name);
      InputHigh(int id);
      ~InputHigh();

      virtual bool evaluateOutput();
      // This gets overridden since it should be able to evaluate without and inputEdges!
      virtual void evaluate();
  private:
  };

  extern InputHigh Assign_InputHigh;
}


#endif //OOPA_CIRCUITSIM_INPUTHIGH_HPP
