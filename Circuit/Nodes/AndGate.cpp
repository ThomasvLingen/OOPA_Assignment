//
// Created by mafn on 3/25/2016.
//

#include "AndGate.hpp"

namespace Circuit {
  AndGate::AndGate(string name)
                   : Node(name) {}

  AndGate::~AndGate() {}

  bool AndGate::evaluateOutput() {
      return this->inputEdges[0]->output && this->inputEdges[1]->output;
  }
}