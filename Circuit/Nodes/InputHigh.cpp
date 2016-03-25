//
// Created by mafn on 3/25/2016.
//

#include "InputHigh.hpp"

namespace Circuit {
  InputHigh Assign_InputHigh(nodeType::INPUT_HIGH);

  InputHigh::InputHigh(string name) : Node(name) {}

  InputHigh::InputHigh(int id) : Node(""){
      NodeFactory::assign(
          id,
          CircuitUtility::Constructor<InputHigh, string>
      );
  }

  InputHigh::~InputHigh() {};

  bool InputHigh::evaluateOutput() {
      return true;
  }

  void InputHigh::evaluate() {
      this->output = this->evaluateOutput();
      this->evaluated = true;

      this->notifyObservers();
  }
}