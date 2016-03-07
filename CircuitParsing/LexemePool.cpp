//
// Created by mafn on 3/5/16.
//

#include "LexemePool.hpp"

namespace CircuitParsing {

  map<LexemeType, string> KnownLexemeNames = {};

  LexemePool::LexemePool() {};

  LexemePool::~LexemePool() {};

  bool LexemePool::isLexeme(LexemeType lexemeType, char character) {
      return this->LexemeTypesCheckers[lexemeType](character);
  }

  void LexemePool::addLexemeToPool(LexemeType type, LexemeTypeChecker typeChecker, bool isSingleChar, string name) {
      this->LexemeTypesCheckers[type] = typeChecker;

      this->LexemeNames[type] = name;
      KnownLexemeNames[type] = name;

      if (isSingleChar) {
          this->SingleCharLexemes.push_back(type);
      }
  }

  ostream& operator<<(ostream& os, LexemeType type){
      string foo = KnownLexemeNames[type];
      os << foo;
      return os;
  }
}