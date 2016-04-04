//
// Created by mafn on 3/25/2016.
//

#ifndef OOPA_CIRCUITSIM_INPUTHIGH_HPP
#define OOPA_CIRCUITSIM_INPUTHIGH_HPP

#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Input.hpp"
#include "CircuitUtility/Constructor.hpp"

namespace Circuit {
  using std::string;

  class InputHigh : public Input {
  public:
      InputHigh(string name);
      InputHigh(int id);
      ~InputHigh();

      virtual bool evaluateOutput();
  private:
  };

  extern InputHigh Assign_InputHigh;
}


#endif //OOPA_CIRCUITSIM_INPUTHIGH_HPP
