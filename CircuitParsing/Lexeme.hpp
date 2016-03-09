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
      // Stage 1
      IDENTIFYER,
      COLON,
      SEMICOLON,
      COMMA,
      // Stage 2
      NODE_IDENTIFYER,
      IS_A, IS_CONNECTED_TO,
      OR, AND, NOT, NOR, NAND, XOR,
      INPUT_LOW, INPUT_HIGH,
      PROBE
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
