//
// Created by mafn on 3/6/16.
//

#ifndef OOPA_CIRCUITSIM_STAGE2LEXER_HPP
#define OOPA_CIRCUITSIM_STAGE2LEXER_HPP

#include "CircuitParsing/Lexeme.hpp"
#include "CircuitParsing/Stage2LexemePool.hpp"

namespace CircuitParsing {
  using std::prev;
  using std::next;

  class Stage2Lexer {
  public:
      Stage2Lexer(LexemeStream input);
      virtual ~Stage2Lexer();

      LexemeStream output;
  private:
      Stage2LexemePool pool;

      void replaceIdentifyers();

      void setDescriptors();
      void setDescriptor(Lexeme& lexeme);

      void setNodeIdentifyers();
      void setNodeIdentifyer(Lexeme& lexeme);

      void transformColon(LexemeStream::iterator);
      void transformColons();
      bool isISA(Lexeme previous, Lexeme next);
      bool isISConnectedTo(Lexeme previous, Lexeme next);
  };
}



#endif //OOPA_CIRCUITSIM_STAGE2LEXER_HPP
