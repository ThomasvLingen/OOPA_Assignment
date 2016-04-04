//
// Created by mafn on 4/4/16.
//

#ifndef OOPA_CIRCUITSIM_PROBE_HPP
#define OOPA_CIRCUITSIM_PROBE_HPP

#include <string>

#include "Circuit/NodeFactory.hpp"
#include "Circuit/NodeTypes.hpp"
#include "Circuit/Nodes/Input.hpp"
#include "CircuitUtility/Constructor.hpp"

namespace Circuit {
  using std::string;

  class Probe : public Node {
  public:
      Probe(string name);
      Probe(int id);
      ~Probe();

      virtual bool evaluateOutput();
  private:
  };

  extern Probe Assign_Probe;
}


#endif //OOPA_CIRCUITSIM_PROBE_HPP
