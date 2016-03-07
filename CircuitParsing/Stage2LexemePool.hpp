//
// Created by mafn on 3/6/16.
//

#ifndef OOPA_CIRCUITSIM_STAGE2LEXEMEPOOL_HPP
#define OOPA_CIRCUITSIM_STAGE2LEXEMEPOOL_HPP

#include <algorithm>

#include "CircuitParsing/LexemePool.hpp"

namespace CircuitParsing {
  using std::map;
  using std::vector;
  using std::string;
  using std::find;

  class Stage2LexemePool : public LexemePool{
  public:
      Stage2LexemePool();
      virtual ~Stage2LexemePool();

      vector<LexemeType> descriptors;

      bool isDescriptor(LexemeType type, string value);
      bool isDescriptor(LexemeType type);
  private:
      virtual void fillPool();
      void addLexemeToPool(LexemeType type, bool isDescriptor, string name);
  };
}



#endif //OOPA_CIRCUITSIM_STAGE2LEXEMEPOOL_HPP
