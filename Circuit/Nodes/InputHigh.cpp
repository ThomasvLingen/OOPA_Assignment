//
// Created by mafn on 3/25/2016.
//

#include "InputHigh.hpp"

namespace Circuit {
  InputHigh::InputHigh(string name)
                       : Node(name) {}

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