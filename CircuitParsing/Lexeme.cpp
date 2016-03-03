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
}
