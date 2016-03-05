//
// Created by mafn on 3/3/2016.
//

#include "Stage1LexemePool.hpp"

namespace CircuitParsing {

  Stage1LexemePool::Stage1LexemePool() {
      this->fillPool();
  }

  void Stage1LexemePool::fillPool() {
      this->addLexemeToPool(
          LexemeType::IDENTIFYER,
          [](char character) {
              return isalpha(character) || isdigit(character) || character == '_';
          },
          false,
          "IDENTIFYER"
      );

      this->addLexemeToPool(
          LexemeType::COLON,
          [](char character) {
              return character == ':';
          },
          true,
          ":"
      );

      this->addLexemeToPool(
          LexemeType::COMMA,
          [](char character) {
              return character == ',';
          },
          true,
          ","
      );

      this->addLexemeToPool(
          LexemeType::SEMICOLON,
          [](char character) {
              return character == ';';
          },
          true,
          ";"
      );
  }

  Stage1LexemePool::~Stage1LexemePool() {};
}