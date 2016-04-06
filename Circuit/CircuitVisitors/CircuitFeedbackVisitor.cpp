//
// Created by mafn on 4/6/16.
//

#include "CircuitFeedbackVisitor.hpp"

namespace CircuitVisitors {
  CircuitFeedbackVisitor::CircuitFeedbackVisitor() {}

  // Assumption 1: for every node, every input has to somehow lead back to an input
  // Assumption 2: This has to ALWAYS be in nodecount or less steps
  // If any of these conditions do not hold up, we're dealing with feedback!
  void CircuitFeedbackVisitor::visit(Circuit::Circuit &elem) {
      for (Circuit::Node* probe : elem.outputs) {
          if (this->hasFeedback(probe, elem.circuit.size())) {
              throw "Feedback was detected for probe " + probe->name;
          }
      }
  }

  bool CircuitFeedbackVisitor::hasFeedback(Circuit::Node *node, int stepsLeft) {
      if (stepsLeft < 0) {
          return true;
      }

      for (Circuit::Node* input : node->inputEdges) {
          if (input->requiredInputs == 0) {
              return false;
          } else {
              return this->hasFeedback(input, stepsLeft-1);
          }
      }
  }
}