//
// Created by mafn on 3/25/2016.
//

#include "InputHigh.hpp"

namespace Circuit {
  InputHigh Assign_InputHigh(nodeType::INPUT_HIGH);

  InputHigh::InputHigh(string name) : Input(name) {}

  InputHigh::InputHigh(int id) : Input(""){
      NodeFactory::assign(
          id,
          CircuitUtility::Constructor<InputHigh, string>
      );
  }

  InputHigh::~InputHigh() {};

  bool InputHigh::evaluateOutput() {
      return true;
  }
}