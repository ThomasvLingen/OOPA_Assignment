//
// Created by mafn on 4/7/16.
//

#include "NandGate.hpp"

namespace Circuit {
  NandGate Assign_NandGate(nodeType::NAND);

  NandGate::NandGate(string name) : Gate(name) {}

  NandGate::NandGate(int id) : Gate("") {
      NodeFactory::assign(
              id,
              CircuitUtility::Constructor<NandGate, string>
      );
  }

  NandGate::~NandGate() {}

  bool NandGate::evaluateOutput() {
      return !(this->inputEdges[0]->output && this->inputEdges[1]->output);
  }
}