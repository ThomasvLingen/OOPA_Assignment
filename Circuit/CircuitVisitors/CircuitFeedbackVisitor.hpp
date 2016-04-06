//
// Created by mafn on 4/6/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUITFEEDBACKVISITOR_HPP
#define OOPA_CIRCUITSIM_CIRCUITFEEDBACKVISITOR_HPP


#include <string>

#include "Circuit/CircuitVisitors/CircuitVisitor.hpp"
#include "Circuit/Circuit.hpp"
#include "Circuit/Nodes/Node.hpp"

namespace CircuitVisitors {
  using std::string;

  class CircuitFeedbackVisitor : public CircuitVisitor {
  public:
      CircuitFeedbackVisitor();

      void visit(Circuit::Circuit &elem);
      bool hasFeedback(Circuit::Node* node, int stepsLeft);
  };

}


#endif //OOPA_CIRCUITSIM_CIRCUITFEEDBACKVISITOR_HPP
