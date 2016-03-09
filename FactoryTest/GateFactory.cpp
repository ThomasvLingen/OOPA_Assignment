//
// Created by mafn on 3/1/16.
//

#include "GateFactory.hpp"

namespace FactoryTest {
  map<string, GateConstructor> GateFactory::gateConstructorMap = {};

  void GateFactory::assign(string name, function<Gate*()> constructor) {
      gateConstructorMap[name] = constructor;
  };

  Gate* GateFactory::create(string name) {
      return gateConstructorMap[name]();
  }
}