//
// Created by mafn on 3/3/2016.
//

#ifndef OOPA_CIRCUITSIM_STAGE1LEXEMEPOOL_HPP
#define OOPA_CIRCUITSIM_STAGE1LEXEMEPOOL_HPP

#include <map>
#include <string>
#include <vector>

#include "Lexeme.hpp"
#include "LexemePool.hpp"

namespace CircuitParsing {
  using std::map;
  using std::vector;
  using std::string;

  class Stage1LexemePool : public LexemePool{
  private:
  public:
      Stage1LexemePool();
      ~Stage1LexemePool();

      virtual void fillPool();
  };
}

#endif //OOPA_CIRCUITSIM_STAGE1LEXEMEPOOL_HPP
