//
// Created by mafn on 4/4/16.
//

#ifndef OOPA_CIRCUITSIM_INPUT_HPP
#define OOPA_CIRCUITSIM_INPUT_HPP

#include <string>

#include "Circuit/Nodes/Node.hpp"

namespace Circuit {
  using std::string;

  class Input : public Node {
  public:
      Input(string name);
      virtual ~Input();

      virtual bool canEvaluate();
  private:
  };
}


#endif //OOPA_CIRCUITSIM_INPUT_HPP
