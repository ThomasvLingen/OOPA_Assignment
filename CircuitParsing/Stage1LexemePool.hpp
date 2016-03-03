//
// Created by mafn on 3/3/2016.
//

#ifndef OOPA_CIRCUITSIM_STAGE1LEXEMEPOOL_HPP
#define OOPA_CIRCUITSIM_STAGE1LEXEMEPOOL_HPP

#include <map>
#include <string>
#include <vector>

#include "Lexeme.hpp"

namespace CircuitParsing {
  using std::map;
  using std::vector;
  using std::string

  class Stage1LexemePool {
  private:
      static void addLexemeToPool(LexemeType type, LexemeTypeChecker typeChecker, bool isSingleChar, string name);
  public:
      static map<LexemeType, string> LexemeNames;
      static map<LexemeType, LexemeTypeChecker> LexemeTypesCheckers;
      static vector<LexemeType> SingleCharLexemes;

      Stage1LexemePool();
      ~Stage1LexemePool();

      static bool isLexeme(LexemeType lexemeType, char character);
      static void fillPool();
  };

  std::ostream& operator<<(std::ostream& os, LexemeType type);
}

#endif //OOPA_CIRCUITSIM_STAGE1LEXEMEPOOL_HPP
