//
// Created by mafn on 4/4/16.
//

#ifndef OOPA_CIRCUITSIM_GATE_HPP
#define OOPA_CIRCUITSIM_GATE_HPP

#include <string>

#include "Circuit/Nodes/Node.hpp"

namespace Circuit{
  using std::string;

  class Gate : public Node {
  public:
      Gate(string name);
  private:
  };
}


#endif //OOPA_CIRCUITSIM_GATE_HPP
