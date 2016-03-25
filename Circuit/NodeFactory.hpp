//
// Created by mafn on 3/25/2016.
//

#ifndef OOPA_CIRCUITSIM_NODEFACTORY_HPP
#define OOPA_CIRCUITSIM_NODEFACTORY_HPP

#include <string>
#include <functional>
#include <map>

namespace Circuit {
  using std::function;
  using std::string;
  using std::map;

  class Node;
  typedef function<Node*(string)> NodeConstructor;
  typedef map<int, NodeConstructor> NodeCatalog;

  class NodeFactory {
  public:
      static void assign(int id, NodeConstructor constructor);
      static Node* create(int id, string name);
      static NodeCatalog& getNodeCatalog();
  private:
  };
}


#endif //OOPA_CIRCUITSIM_NODEFACTORY_HPP
