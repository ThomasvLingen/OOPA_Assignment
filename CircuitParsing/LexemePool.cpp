//
// Created by mafn on 3/5/16.
//

#include "LexemePool.hpp"

namespace CircuitParsing {

  LexemePool::LexemePool() {};

  LexemePool::~LexemePool() {};

  bool LexemePool::isLexeme(LexemeType lexemeType, char character) {
      return this->LexemeTypesCheckers[lexemeType](character);
  }

  void LexemePool::addLexemeToPool(LexemeType type, LexemeTypeChecker typeChecker, bool isSingleChar, string name) {
      this->LexemeTypesCheckers[type] = typeChecker;
      this->LexemeNames[type] = name;

      if (isSingleChar) {
          this->SingleCharLexemes.push_back(type);
      }
  }
}