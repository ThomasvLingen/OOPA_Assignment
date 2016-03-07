//
// Created by mafn on 3/5/16.
//

#ifndef OOPA_CIRCUITSIM_LEXEMEPOOL_HPP
#define OOPA_CIRCUITSIM_LEXEMEPOOL_HPP

#include <map>

#include "CircuitParsing/Lexeme.hpp"

namespace CircuitParsing {
  using std::map;
  using std::string;
  using std::ostream;

  // This is to track all LexemeNames ever added to a pool. Therefore spans multiple pools!
  extern map<LexemeType, string> KnownLexemeNames;

  class LexemePool {
  private:
  public:
      void addLexemeToPool(LexemeType type, LexemeTypeChecker typeChecker, bool isSingleChar, string name);
      map<LexemeType, string> LexemeNames;
      map<LexemeType, LexemeTypeChecker> LexemeTypesCheckers;
      vector<LexemeType> SingleCharLexemes;

      LexemePool();
      virtual ~LexemePool();

      bool isLexeme(LexemeType lexemeType, char character);
      virtual void fillPool()=0;
  };

  ostream& operator<<(ostream& os, LexemeType type);
}



#endif //OOPA_CIRCUITSIM_LEXEMEPOOL_HPP
