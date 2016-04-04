//
// Created by mafn on 3/25/2016.
//

#include "Node.hpp"

namespace Circuit {
  Node::Node(string name) {
      this->name = name;

      this->evaluated = false;
      this->output = false;
  }

  void Node::evaluate() {
      if (this->canEvaluate()) {
          this->output = this->evaluateOutput();
          this->evaluated = true;

          this->notifyObservers();
      }
  }

  bool Node::canEvaluate() {
      if (this->inputEdges.size() != this->requiredInputs) {
          return false;
      }

      bool allInputsEvaluated = true;

      for (Node* node : this->inputEdges) {
          // Fancy!
          allInputsEvaluated &= node->evaluated;
      }

      return allInputsEvaluated;
  }

  void Node::addInput(Node *toAdd) {
      if (this->inputEdges.size() < this->requiredInputs) {
          this->inputEdges.push_back(toAdd);
          this->observe(*toAdd);
      } else {
          cout << "Warning: a node has been issued to add an edge 3 times, which should only be done twice!" << endl;
      }
  }

  void Node::addEdge(Node *toAdd) {
      toAdd->addInput(this);
  }

  void Node::update() {
      this->evaluate();
  }
}