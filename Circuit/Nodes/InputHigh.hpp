//
// Created by mafn on 3/25/2016.
//

#ifndef OOPA_CIRCUITSIM_INPUTHIGH_HPP
#define OOPA_CIRCUITSIM_INPUTHIGH_HPP

#include <string>

#include "Circuit/Nodes/Node.hpp"

namespace Circuit {
  using std::string;

  class InputHigh : public Node {
  public:
      InputHigh(string name);
      ~InputHigh();

      virtual bool evaluateOutput();
      // This gets overridden since it should be able to evaluate without and inputEdges!
      virtual void evaluate();
  private:
  };
}


#endif //OOPA_CIRCUITSIM_INPUTHIGH_HPP
