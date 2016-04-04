//
// Created by mafn on 4/4/16.
//

#ifndef OOPA_CIRCUITSIM_INPUTLOW_HPP
#define OOPA_CIRCUITSIM_INPUTLOW_HPP
#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Input.hpp"
#include "CircuitUtility/Constructor.hpp"

namespace Circuit {
  using std::string;

  class InputLow : public Input {
  public:
      InputLow(string name);
      InputLow(int id);
      ~InputLow();

      virtual bool evaluateOutput();
  private:
  };

  extern InputLow Assign_InputLow;
}


#endif //OOPA_CIRCUITSIM_INPUTLOW_HPP
