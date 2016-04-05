//
// Created by mafn on 4/4/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUIT_HPP
#define OOPA_CIRCUITSIM_CIRCUIT_HPP

#include <vector>
#include <string>

#include "CircuitParsing/InputFileData.hpp"
#include "CircuitParsing/InputFileNode.hpp"
#include "Circuit/Nodes/Node.hpp"
#include "Circuit/NodeFactory.hpp"
#include "Circuit/CircuitVisitors/CircuitVisitor.hpp"

namespace Circuit {
  using std::vector;
  using std::string;
  using CircuitParsing::InputFileData;
  using CircuitParsing::InputFileNode;

  class Circuit {
  public:
      Circuit(InputFileData& inputCircuit);
      virtual ~Circuit();

      vector<Node*> circuit;
      vector<Node*> inputs;

      void evaluateCircuit();

      void accept(CircuitVisitors::CircuitVisitor& v);
  private:

      void constructCircuit(InputFileData& inputCircuit);
      void constructNodes(vector<InputFileNode> circuitNodes);
      void constructEdges(CircuitParsing::edgeMap edgeMap);
      void constructEdge(InputFileNode* origin, vector<InputFileNode*> targets);

      bool isInputNode(Node* node);

      Node* getNode(string name);
  };
}


#endif //OOPA_CIRCUITSIM_CIRCUIT_HPP
