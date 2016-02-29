//
// Created by mafn on 2/28/2016.
//

#ifndef OOPA_CIRCUITLEXEME_HPP
#define OOPA_CIRCUITLEXEME_HPP

#include <string>
#include <vector>
#include <map>
#include <regex>

namespace CircuitParsing {
  using std::string;
  using std::vector;
  using std::map;
  using std::regex_match;

  enum LexemeType {
      IDENTIFYER,
      COLON,
      SEMICOLON,
      COMMA
  };

  static map<LexemeType, string> LexemeTypesRegex = {
          {LexemeType::IDENTIFYER, "[a-zA-Z0-9_]"},
          {LexemeType::COLON, ":"},
          {LexemeType::SEMICOLON, ";"},
          {LexemeType::COMMA, ","}
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
}

#endif //OOPA_CIRCUITLEXEME_HPP
