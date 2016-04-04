//
// Created by mafn on 4/4/16.
//

#include "OrGate.hpp"

namespace Circuit {
  OrGate Assign_OrGate(nodeType::OR);

  OrGate::OrGate(string name) : Gate(name) {}

  OrGate::OrGate(int id) : Gate("") {
      NodeFactory::assign(
              id,
              CircuitUtility::Constructor<OrGate, string>
      );
  }

  OrGate::~OrGate() {}

  bool OrGate::evaluateOutput() {
      return this->inputEdges[0]->output || this->inputEdges[1]->output;
  }
}