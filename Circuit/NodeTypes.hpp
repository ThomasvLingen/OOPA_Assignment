//
// Created by mafn on 3/14/16.
//

#ifndef OOPA_CIRCUITSIM_NODETYPES_HPP
#define OOPA_CIRCUITSIM_NODETYPES_HPP

#include <map>

#include "CircuitParsing/Lexeme.hpp"

namespace Circuit {
  using std::map;

  enum nodeType {
      OR, AND, NOT,
      NOR, NAND, XOR,
      INPUT_HIGH, INPUT_LOW,
      PROBE
  };

  extern map<CircuitParsing::LexemeType, nodeType> lexemeTypeToNodeTypeMap;

  nodeType lexemeTypeToNodeType(CircuitParsing::LexemeType);
}

#endif //OOPA_CIRCUITSIM_NODETYPES_HPP
