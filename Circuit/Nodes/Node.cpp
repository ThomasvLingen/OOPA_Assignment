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
      } else {
          cout << "Warning: a node has been issued to evaluate when it cannot (no input nodes / input nodes not evaled)" << endl;
      }
  }

  bool Node::canEvaluate() {
      // This has to be specifically checked first, to prevent us from checking a non-existant value
      if (this->inputEdges[0] && this->inputEdges[1]) {
          return this->inputEdges[0]->evaluated && this->inputEdges[1]->evaluated;
      } else {
          return false;
      }
  }

  void Node::addEdge(Node *toAdd) {
      if (this->inputEdges.size() <= 2) {
          this->inputEdges.push_back(toAdd);
          this->observe(*toAdd);
      } else {
          cout << "Warning: a node has been issued to add an edge 3 times, which should only be done twice!" << endl;
      }
  }

  void Node::update() {
      this->evaluate();
  }
}