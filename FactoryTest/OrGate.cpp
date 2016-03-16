//
// Created by mafn on 3/1/16.
//

#include "OrGate.hpp"

namespace FactoryTest {
  OrGate OrGate::m_OrGate("OR");

  // Assigns the gate to the factory
  OrGate::OrGate(string type) : Gate(type) {
      GateFactory::assign(type, orConstructor);
  }

  OrGate::OrGate() : Gate() {
    this->type = "I AM AN OR GATE!";
  };

  OrGate* orConstructor() {
      return new OrGate();
  };

  OrGate::~OrGate() {};
}
