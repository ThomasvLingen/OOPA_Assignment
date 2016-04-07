//
// Created by mafn on 4/7/16.
//

#include "NorGate.hpp"

namespace Circuit {
  NorGate Assign_NorGate(nodeType::NOR);

  NorGate::NorGate(string name) : Gate(name) {}

  NorGate::NorGate(int id) : Gate("") {
      NodeFactory::assign(
              id,
              CircuitUtility::Constructor<NorGate, string>
      );
  }

  NorGate::~NorGate() {}

  bool NorGate::evaluateOutput() {
      return !(this->inputEdges[0]->output || this->inputEdges[1]->output);
  }
}