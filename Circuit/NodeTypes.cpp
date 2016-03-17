//
// Created by mafn on 3/14/16.
//

#include "Circuit/NodeTypes.hpp"

// TODO: This entire file is dumb and should be refactored.

namespace Circuit {
  // TODO: there has to be a cleaner way to do this instead of straight up harcoding it...
  map<CircuitParsing::LexemeType, nodeType> lexemeTypeToNodeTypeMap = {
          {CircuitParsing::LexemeType::OR, nodeType::OR},
          {CircuitParsing::LexemeType::AND, nodeType::AND},
          {CircuitParsing::LexemeType::NOT, nodeType::NOT},
          {CircuitParsing::LexemeType::NOR, nodeType::NOR},
          {CircuitParsing::LexemeType::NAND, nodeType::NAND},
          {CircuitParsing::LexemeType::XOR, nodeType::XOR},
          {CircuitParsing::LexemeType::INPUT_HIGH, nodeType::INPUT_HIGH},
          {CircuitParsing::LexemeType::INPUT_LOW, nodeType::INPUT_LOW},
          {CircuitParsing::LexemeType::PROBE, nodeType::PROBE},
  };

  map<nodeType, string> nodeTypeNames = {
          {nodeType::AND, "AND"},
          {nodeType::INPUT_HIGH, "INPUT_HIGH"},
          {nodeType::INPUT_LOW, "INPUT_LOW"},
          {nodeType::NAND, "NAND"},
          {nodeType::NOR, "NOR"},
          {nodeType::NOT, "NOT"},
          {nodeType::OR, "OR"},
          {nodeType::PROBE, "PROBE"},
          {nodeType::XOR, "XOR"}
  };

  // TODO: This should also be extracted to a clean LexemeUtils / ParseUtils class
  nodeType lexemeTypeToNodeType(CircuitParsing::LexemeType lexemetype) {
      return lexemeTypeToNodeTypeMap[lexemetype];
  }

  ostream& operator<<(ostream& os, nodeType type){
    string foo = nodeTypeNames[type];
    os << foo;
    return os;
  }
}