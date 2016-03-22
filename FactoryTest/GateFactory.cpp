//
// Created by mafn on 3/1/16.
//

#include "GateFactory.hpp"

namespace FactoryTest {
  void GateFactory::assign(string name, function<Gate*()> constructor) {
      GateConstructorMap& map = GateFactory::getGateConstructorMap();

      map[name] = constructor;
  };

  Gate* GateFactory::create(string name) {
      GateConstructorMap& map = GateFactory::getGateConstructorMap();

      return map[name]();
  }

  GateConstructorMap& GateFactory::getGateConstructorMap() {
      static GateConstructorMap gateConstructorMap;

      return gateConstructorMap;
  }
}