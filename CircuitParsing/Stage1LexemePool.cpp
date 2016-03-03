//
// Created by mafn on 3/3/2016.
//

#include "Stage1LexemePool.hpp"

namespace CircuitParsing {
  map<LexemeType, string> Stage1LexemePool::LexemeNames;
  map<LexemeType, LexemeTypeChecker> Stage1LexemePool::LexemeTypesCheckers;
  vector<LexemeType> Stage1LexemePool::SingleCharLexemes;

  Stage1LexemePool::Stage1LexemePool() {
      static bool isInitialised = false;

      if (!isInitialised) {
          isInitialised = true;

          fillPool();
      }
  }

  void Stage1LexemePool::fillPool() {
      Stage1LexemePool::addLexemeToPool(
          LexemeType::IDENTIFYER,
          [](char character) {
              return isalpha(character) || isdigit(character) || character == '_';
          },
          false,
          "IDENTIFYER"
      );

      Stage1LexemePool::addLexemeToPool(
          LexemeType::COLON,
          [](char character) {
              return character == ':';
          },
          true,
          ":"
      );

      Stage1LexemePool::addLexemeToPool(
          LexemeType::COMMA,
          [](char character) {
              return character == ',';
          },
          true,
          ","
      );

      Stage1LexemePool::addLexemeToPool(
          LexemeType::SEMICOLON,
          [](char character) {
              return character == ';';
          },
          true,
          ";"
      );
  }

  Stage1LexemePool::~Stage1LexemePool() {};

  bool Stage1LexemePool::isLexeme(LexemeType lexemeType, char character) {
      LexemeTypesCheckers[lexemeType](character);
  }

  void Stage1LexemePool::addLexemeToPool(LexemeType type, LexemeTypeChecker typeChecker, bool isSingleChar, string name) {
      LexemeTypesCheckers[type] = typeChecker;
      LexemeNames[type] = name;

      if (isSingleChar) {
          SingleCharLexemes.push_back(type);
      }
  }

  std::ostream& operator<<(std::ostream& os, LexemeType type){
      string foo = Stage1LexemePool::LexemeNames[type];
      os << foo;
      return os;
  }
}