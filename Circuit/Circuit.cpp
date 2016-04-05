//
// Created by mafn on 4/4/16.
//

#include "Circuit.hpp"

namespace Circuit {
  Circuit::Circuit(CircuitParsing::InputFileData &inputCircuit) {
      this->constructCircuit(inputCircuit);
  }

  Circuit::~Circuit() {}

  void Circuit::constructCircuit(InputFileData& inputCircuit) {
      this->constructNodes(inputCircuit.nodes);
      this->constructEdges(inputCircuit.edges);
  }

  void Circuit::constructNodes(vector<InputFileNode> circuitNodes) {
      for (InputFileNode& node : circuitNodes) {
          this->circuit.push_back(NodeFactory::create(node.type, node.name));
      }
  }

  void Circuit::constructEdges(CircuitParsing::edgeMap edgeMap) {
      for (std::pair<InputFileNode*, vector<InputFileNode *>> mapEntry : edgeMap) {
          this->constructEdge(mapEntry.first, mapEntry.second);
      }
  }

  void Circuit::constructEdge(InputFileNode *origin, vector<InputFileNode *> targets) {
      Node* originNode = this->getNode(origin->name);

      for (InputFileNode* target : targets) {
          Node* targetNode = this->getNode(target->name);

          originNode->addEdge(targetNode);
      }
  }

  Node* Circuit::getNode(string name) {
      for (Node* node : this->circuit) {
         if (node->name == name) {
             return node;
         }
      }

      return nullptr;
  }
}