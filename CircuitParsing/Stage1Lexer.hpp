//
// Created by mafn on 2/28/2016.
//

#ifndef OOPA_STAGE1LEXER_HPP
#define OOPA_STAGE1LEXER_HPP

#include <fstream>
#include <iostream>
#include <vector>

#include "Lexeme.hpp"
#include "Stage1LexemePool.hpp"
#include "../CircuitUtility/StrUtil.hpp"

namespace CircuitParsing {
  //TODO: use proper using directives instead of pulling in the entirety of std
  using namespace std;
  using CircuitParsing::Lexeme;

  class Stage1Lexer {
  public:
      Stage1Lexer(string filename);
      virtual ~Stage1Lexer();

      LexemeStream output;
  private:
      Stage1LexemePool pool;

      LexemeStream lexLine(string line);
      string removeComments(string line);
      void addToOutput(LexemeStream toAdd);
      bool currentCharIsLexeme(string::iterator currentChar, LexemeType type);
      bool nextCharIsLexeme(string::iterator currentChar, LexemeType type);
  };
}

#endif //OOPA_STAGE1LEXER_HPP
