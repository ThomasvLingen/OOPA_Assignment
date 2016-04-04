//
// Created by mafn on 4/4/16.
//

#include "Gate.hpp"

namespace Circuit {
  Gate::Gate(string name) : Node(name) {

  }

  bool Gate::canEvaluate() {
      // This has to be specifically checked first, to prevent us from checking a non-existant value
      if (this->inputEdges[0] && this->inputEdges[1]) {
          return this->inputEdges[0]->evaluated && this->inputEdges[1]->evaluated;
      } else {
          return false;
      }
  }
}