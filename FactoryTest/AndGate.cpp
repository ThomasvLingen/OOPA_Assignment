//
// Created by mafn on 3/1/16.
//

#include "AndGate.hpp"

namespace FactoryTest {
  AndGate::AndGate(string type) : Gate(type) {
      GateFactory::assign(type, this->constructor());
  }

  AndGate::AndGate() : Gate() {
      this->type = "AND LOL";
  };
  AndGate::~AndGate() {};

  Gate* AndGate::constructor() {
      return new AndGate();
  }
}