//
// Created by mafn on 4/4/16.
//

#include "Probe.hpp"

namespace Circuit {
  Probe Assign_Probe(nodeType::PROBE);

  Probe::Probe(string name) : Node(name){
      this->requiredInputs = 1;
      this->isConstant = false;
  }

  Probe::Probe(int id) : Node() {
      NodeFactory::assign(
              id,
              CircuitUtility::Constructor<Probe, string>
      );
  }

  Probe::~Probe() {}

  bool Probe::evaluateOutput() {
      return this->inputEdges[0]->output;
  }
}