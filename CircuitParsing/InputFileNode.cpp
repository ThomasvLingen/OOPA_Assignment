//
// Created by mafn on 3/14/16.
//

#include "InputFileNode.hpp"

namespace CircuitParsing {
  InputFileNode::InputFileNode(Circuit::nodeType type, string name) {
      this->type = type;
      this->name = name;
  }

  InputFileNode::~InputFileNode() {};
};