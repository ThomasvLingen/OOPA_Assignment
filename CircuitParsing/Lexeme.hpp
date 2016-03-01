//
// Created by mafn on 2/28/2016.
//

#ifndef OOPA_CIRCUITLEXEME_HPP
#define OOPA_CIRCUITLEXEME_HPP

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>

namespace CircuitParsing {
  using std::string;
  using std::vector;
  using std::map;

  enum LexemeType {
      IDENTIFYER,
      COLON,
      SEMICOLON,
      COMMA
  };

  static map<LexemeType, std::function<bool(char)>> LexemeTypesCheckers = {
      {LexemeType::COLON,
          [](char character) {
              return character == ':';
          }
      },
      {LexemeType::SEMICOLON,
          [](char character) {
              return character == ';';
          }
      },
      {LexemeType::COMMA,
          [](char character) {
              return character == ',';
          }
      },
      {LexemeType::IDENTIFYER,
          [](char character) {
              return isalpha(character) || isdigit(character) || character == '_';
          }
      }
  };

  class Lexeme {
  public:

      Lexeme(LexemeType type, string value);
      virtual ~Lexeme();

      LexemeType type;
      string value;

      static bool isLexeme(LexemeType lexemeType, char character);
  };

  typedef vector<Lexeme> LexemeStream;
  std::ostream& operator<<(std::ostream& os, LexemeType type);
}

#endif //OOPA_CIRCUITLEXEME_HPP
