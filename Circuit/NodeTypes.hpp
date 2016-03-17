//
// Created by mafn on 3/14/16.
//

#ifndef OOPA_CIRCUITSIM_NODETYPES_HPP
#define OOPA_CIRCUITSIM_NODETYPES_HPP

#include <map>
#include <string>
#include <ostream>

#include "CircuitParsing/Lexeme.hpp"

namespace Circuit {
  using std::map;
  using std::string;
  using std::ostream;

  enum nodeType {
      OR, AND, NOT,
      NOR, NAND, XOR,
      INPUT_HIGH, INPUT_LOW,
      PROBE
  };

  extern map<CircuitParsing::LexemeType, nodeType> lexemeTypeToNodeTypeMap;
  extern map<nodeType, string> nodeTypeNames;

  nodeType lexemeTypeToNodeType(CircuitParsing::LexemeType);

  ostream& operator<<(ostream& os, nodeType type);
}

#endif //OOPA_CIRCUITSIM_NODETYPES_HPP
