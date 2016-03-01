//
// Created by mafn on 3/1/16.
//

#include "GateFactory.hpp"

namespace FactoryTest {
  void GateFactory::assign(string name, Gate* gate) {
      gateMap[name] = gate;
  };

  Gate* GateFactory::create(string name) {
      return gateMap[name]->constructor();
  }
}