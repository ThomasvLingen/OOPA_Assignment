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
      return LexemeTypesCheckers[lexemeType](character);
  }

  std::ostream& operator<<(std::ostream& os, LexemeType type){
      switch(type){
          case LexemeType::IDENTIFYER: os << "IDENTIFIER"; return os;
          case LexemeType::COLON: os << ":"; return os;
          case LexemeType::SEMICOLON: os << ";"; return os;
          case LexemeType::COMMA: os << ","; return os;
      }
  }
}
