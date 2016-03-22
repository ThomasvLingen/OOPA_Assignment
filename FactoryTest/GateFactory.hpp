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
  typedef map<string, GateConstructor> GateConstructorMap;

  class GateFactory {
  public:
      static void assign(string name, GateConstructor constructor);
      static Gate* create(string name);
      static GateConstructorMap& getGateConstructorMap();
  private:
  };
}


#endif //OOPA_CIRCUITSIM_GATEFACTORY_HPP
