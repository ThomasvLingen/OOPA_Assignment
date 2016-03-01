//
// Created by mafn on 3/1/16.
//

#ifndef OOPA_CIRCUITSIM_GATEFACTORY_HPP
#define OOPA_CIRCUITSIM_GATEFACTORY_HPP

#include <string>
#include <functional>
#include <map>

#include "Gate.hpp"

namespace FactoryTest {
  using namespace std;

  class Gate;

  static map<string, Gate*> gateMap = {};

  class GateFactory {
  public:
      static void assign(string name, Gate* constructor);
      static Gate* create(string name);
  private:
  };
}


#endif //OOPA_CIRCUITSIM_GATEFACTORY_HPP
