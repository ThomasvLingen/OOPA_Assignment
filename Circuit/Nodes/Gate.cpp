//
// Created by mafn on 4/4/16.
//

#include "Gate.hpp"

namespace Circuit {
  Gate::Gate(string name) : Node(name) {
      // This is merely a default a value, and can be overriden in concrete gates (f/e NOT gate)
      this->requiredInputs = 2;
  }
}