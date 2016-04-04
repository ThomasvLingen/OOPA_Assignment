//
// Created by mafn on 4/4/16.
//

#include "InputLow.hpp"

namespace Circuit {
  InputLow Assign_InputLow(nodeType::INPUT_LOW);

  InputLow::InputLow(int id) : Input("") {
      NodeFactory::assign(
              id,
              CircuitUtility::Constructor<InputLow, string>
      );
  }

  InputLow::InputLow(string name) : Input(name) {

  }

  InputLow::~InputLow() {};

  bool InputLow::evaluateOutput() {
      return false;
  }
}