//
// Created by mafn on 4/4/16.
//

#include "NotGate.hpp"

namespace Circuit {
  NotGate Assign_NotGate(nodeType::NOT);

  NotGate::NotGate(string name) : Gate(name) {
      this->requiredInputs = 1;
  }

  NotGate::NotGate(int id) : Gate("") {
      NodeFactory::assign(
              id,
              CircuitUtility::Constructor<NotGate, string>
      );
  }

  NotGate::~NotGate() {}

  bool NotGate::evaluateOutput() {
      return !this->inputEdges[0]->output;
  }
}