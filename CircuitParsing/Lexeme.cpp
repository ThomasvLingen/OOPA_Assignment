//
// Created by mafn on 2/28/2016.
//

#include "Lexeme.hpp"

namespace CircuitParsing {
  Lexeme::Lexeme(LexemeType type, string value) {
      this->type = type;
      this->value = value;
  }

  Lexeme::~Lexeme() {};

  bool Lexeme::isLexeme(LexemeType lexemeType, char character) {
      string charStr(1, character);
      return regex_match(charStr, std::regex(LexemeTypesRegex[lexemeType]));
  }
}
