//
// Created by mafn on 3/14/16.
//

#ifndef OOPA_CIRCUITSIM_INPUTFILENODE_HPP
#define OOPA_CIRCUITSIM_INPUTFILENODE_HPP

#include <string>

#include "Circuit/NodeTypes.hpp"

namespace CircuitParsing {
  using std::string;

  class InputFileNode {
  private:
  public:
      InputFileNode(Circuit::nodeType type, string name);
      virtual ~InputFileNode();

      Circuit::nodeType type;
      string name;
  };
}


#endif //OOPA_CIRCUITSIM_INPUTFILENODE_HPP
