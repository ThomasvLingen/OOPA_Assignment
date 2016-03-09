//
// Created by mafn on 3/1/16.
//

#ifndef OOPA_CIRCUITSIM_GATEFACTORY_HPP
#define OOPA_CIRCUITSIM_GATEFACTORY_HPP

#include <string>
#include <functional>
#include <map>

namespace FactoryTest {
  using namespace std;
  class Gate;


  typedef function<Gate*()> GateConstructor;

  class GateFactory {
  public:
      static map<string, GateConstructor> gateConstructorMap;

      static void assign(string name, GateConstructor constructor);
      static Gate* create(string name);
  private:
  };
}


#endif //OOPA_CIRCUITSIM_GATEFACTORY_HPP
