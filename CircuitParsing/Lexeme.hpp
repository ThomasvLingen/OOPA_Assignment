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
  using std::function;

  enum LexemeType {
      IDENTIFYER,
      COLON,
      SEMICOLON,
      COMMA
  };

  typedef function<bool(char)> LexemeTypeChecker;

  // Instead of having a bunch of namespaced 'globals', this should probably be solved with a class managing a lexeme pool.
  // TODO: write a proper LexemePool class
  extern map<LexemeType, LexemeTypeChecker> LexemeTypesCheckers;
  extern map<LexemeType, string> LexemeNames;
  extern vector<LexemeType> SingleCharLexemes;

  class Lexeme {
  public:
      Lexeme();
      Lexeme(LexemeType type, string value);
      virtual ~Lexeme();

      LexemeType type;
      string value;

      static bool isLexeme(LexemeType lexemeType, char character);

  private:
      static void addLexemeToPool(LexemeType type, LexemeTypeChecker typeChecker, bool isSingleChar, string name);
  };

  typedef vector<Lexeme> LexemeStream;

  std::ostream& operator<<(std::ostream& os, LexemeType type);
}

#endif //OOPA_CIRCUITLEXEME_HPP
