//
// Created by mafn on 3/6/16.
//

#include "Stage2LexemePool.hpp"

namespace CircuitParsing {
  Stage2LexemePool::Stage2LexemePool() {
      this->fillPool();
  }

  Stage2LexemePool::~Stage2LexemePool() {};

  void Stage2LexemePool::fillPool() {
      this->addLexemeToPool(LexemeType::NODE_IDENTIFYER, false, "NODE_IDENTIFYER");
      this->addLexemeToPool(LexemeType::IS_A, false, "IS_A");
      this->addLexemeToPool(LexemeType::IS_CONNECTED_TO, false, "IS_CONNECTED_TO");

      this->addLexemeToPool(LexemeType::OR, true, "OR");
      this->addLexemeToPool(LexemeType::AND, true, "AND");
      this->addLexemeToPool(LexemeType::NOT, true, "NOT");
      this->addLexemeToPool(LexemeType::NOR, true, "NOR");
      this->addLexemeToPool(LexemeType::NAND, true, "NAND");
      this->addLexemeToPool(LexemeType::XOR, true, "XOR");
      this->addLexemeToPool(LexemeType::INPUT_LOW, true, "INPUT_LOW");
      this->addLexemeToPool(LexemeType::INPUT_HIGH, true, "INPUT_HIGH");
      this->addLexemeToPool(LexemeType::PROBE, true, "PROBE");
  }

  void Stage2LexemePool::addLexemeToPool(LexemeType type, bool isDescriptor, string name) {
      this->LexemeNames[type] = name;
      KnownLexemeNames[type] = name;

      if (isDescriptor) {
         this->descriptors.push_back(type);
      }
  }

  bool Stage2LexemePool::isDescriptor(LexemeType type, string value) {
      return LexemeNames[type] == value;
  }

  bool Stage2LexemePool::isDescriptor(LexemeType type) {
      return find(this->descriptors.begin(), this->descriptors.end(), type) != this->descriptors.end();
  };

}