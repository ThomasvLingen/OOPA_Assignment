//
// Created by mafn on 4/4/16.
//

#include "Input.hpp"

namespace Circuit {

  Input::Input(string name) : Node(name) {

  }

  bool Input::canEvaluate() {
      return true;
  }
}