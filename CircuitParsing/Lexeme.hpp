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
  using std::function;

  enum LexemeType {
      IDENTIFYER,
      COLON,
      SEMICOLON,
      COMMA
  };

  typedef function<bool(char)> LexemeTypeChecker;

  class Lexeme {
  public:
      Lexeme();
      Lexeme(LexemeType type, string value);
      virtual ~Lexeme();

      LexemeType type;
      string value;
  private:
  };

  typedef vector<Lexeme> LexemeStream;
}

#endif //OOPA_CIRCUITLEXEME_HPP
