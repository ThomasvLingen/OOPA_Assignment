//
// Created by mafn on 4/7/16.
//

#include "XorGate.hpp"

namespace Circuit {
  XorGate Assign_XorGate(nodeType::XOR);

  XorGate::XorGate(string name) : Gate(name) {}

  XorGate::XorGate(int id) : Gate("") {
      NodeFactory::assign(
              id,
              CircuitUtility::Constructor<XorGate, string>
      );
  }

  XorGate::~XorGate() {}

  bool XorGate::evaluateOutput() {
      return this->inputEdges[0]->output ^ this->inputEdges[1]->output;
  }
}
