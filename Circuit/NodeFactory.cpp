//
// Created by mafn on 3/25/2016.
//

#include "NodeFactory.hpp"

namespace Circuit {
  NodeCatalog& NodeFactory::getNodeCatalog() {
      static NodeCatalog nodeFactoryCatalog;

      return nodeFactoryCatalog;
  }

  Node* NodeFactory::create(int id, string name) {
      NodeCatalog& catalog = NodeFactory::getNodeCatalog();

      return catalog[id](name);
  }

  void NodeFactory::assign(int id, NodeConstructor constructor) {
      NodeCatalog& catalog = NodeFactory::getNodeCatalog();

      catalog[id] = constructor;
  }
}