//
// Created by mafn on 3/14/16.
//

#ifndef OOPA_CIRCUITSIM_INPUTFILEDATA_HPP
#define OOPA_CIRCUITSIM_INPUTFILEDATA_HPP

#include <vector>
#include <map>

#include "CircuitParsing/InputFileNode.hpp"

namespace CircuitParsing {
  using std::vector;
  using std::map;

  class InputFileData {
  private:
  public:
      InputFileData();
      virtual ~InputFileData();

      vector<InputFileNode> nodes;
      map<InputFileNode*, vector<InputFileNode*>> edges;
      InputFileNode* getNode(string name);
  };

  typedef vector<InputFileNode*> InputFileNodeStream;
}


#endif //OOPA_CIRCUITSIM_INPUTFILEDATA_HPP
