//
// Created by mafn on 3/1/16.
//

#include "AndGate.hpp"

namespace FactoryTest {
  // Assigns the gate to the factory
  AndGate::AndGate(string type) : Gate(type) {
      GateFactory::assign(type, andConstructor);
  }

  AndGate::AndGate() : Gate() {
      this->type = "I AM AN AND GATE!";
  };

  AndGate* andConstructor(){
      return new AndGate();
  };

  AndGate::~AndGate() {};
}