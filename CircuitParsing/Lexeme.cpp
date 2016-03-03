//
// Created by mafn on 2/28/2016.
//

#include "Lexeme.hpp"

namespace CircuitParsing {
  map<LexemeType, LexemeTypeChecker> LexemeTypesCheckers;
  map<LexemeType, string> LexemeNames;
  vector<LexemeType> SingleCharLexemes;

  Lexeme::Lexeme() {
      Lexeme::addLexemeToPool(
          LexemeType::IDENTIFYER,
          [](char character) {
             return isalpha(character) || isdigit(character) || character == '_';
          },
          false,
          "IDENTIFYER"
      );

      Lexeme::addLexemeToPool(
          LexemeType::COLON,
          [](char character) {
              return character == ':';
          },
          true,
          ":"
      );

      Lexeme::addLexemeToPool(
          LexemeType::COMMA,
          [](char character) {
              return character == ',';
          },
          true,
          ","
      );

      Lexeme::addLexemeToPool(
          LexemeType::SEMICOLON,
          [](char character) {
              return character == ';';
          },
          true,
          ";"
      );
  };

  Lexeme::Lexeme(LexemeType type, string value) {
      this->type = type;
      this->value = value;
  }

  Lexeme::~Lexeme() {};

  bool Lexeme::isLexeme(LexemeType lexemeType, char character) {
      return LexemeTypesCheckers[lexemeType](character);
  }

  void Lexeme::addLexemeToPool(LexemeType type, LexemeTypeChecker typeChecker, bool isSingleChar, string name) {
      LexemeTypesCheckers[type] = typeChecker;
      LexemeNames[type] = name;

      if (isSingleChar) {
         SingleCharLexemes.push_back(type);
      }
  }

  std::ostream& operator<<(std::ostream& os, LexemeType type){
      os << LexemeNames[type];
      return os;
  }
}
