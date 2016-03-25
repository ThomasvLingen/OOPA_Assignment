//
// Created by mafn on 3/25/2016.
//

#ifndef OOPA_CIRCUITSIM_ANDGATE_HPP
#define OOPA_CIRCUITSIM_ANDGATE_HPP

#include <string>

#include "Circuit/Nodes/Node.hpp"

namespace Circuit {
  using std::string;

  class AndGate : public Node {
  public:
      AndGate(string name);
      ~AndGate();

      virtual bool evaluateOutput();
  private:
  };
}


#endif //OOPA_CIRCUITSIM_ANDGATE_HPP
