//
// Created by mafn on 3/25/2016.
//

#ifndef OOPA_CIRCUITSIM_NODE_HPP
#define OOPA_CIRCUITSIM_NODE_HPP

#include <vector>
#include <iostream>
#include <string>

#include "Circuit/Observer.hpp"
#include "Circuit/Observed.hpp"


namespace Circuit {
  using std::vector;
  using std::cout;
  using std::endl;
  using std::string;

  class Node : public Observer, public Observed {
  public:
      Node(string name="DEFAULT_NAME");

      string name;
      vector<Node*> inputEdges;
      int requiredInputs;
      bool output;
      bool evaluated;

      virtual bool canEvaluate();
      virtual bool evaluateOutput()=0;
      virtual void update();
      void evaluate();

      void addInput(Node* toAdd);
      void addEdge(Node* toAdd);
  private:
  };
}



#endif //OOPA_CIRCUITSIM_NODE_HPP
