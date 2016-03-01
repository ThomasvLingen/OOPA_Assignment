//
// Created by mafn on 3/1/16.
//

#include "OrGate.hpp"

namespace FactoryTest {
  OrGate::OrGate(string type) : Gate(type) {
      GateFactory::assign(type, this->constructor());
  }

  OrGate::OrGate() : Gate() {
    this->type = "OR LOL";
  };

  OrGate::~OrGate() {};

  Gate* OrGate::constructor() {
      return new OrGate();
  }
}
