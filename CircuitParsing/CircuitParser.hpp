//
// Created by mafn on 3/14/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUITPARSER_HPP
#define OOPA_CIRCUITSIM_CIRCUITPARSER_HPP

#include <functional>

#include "CircuitParsing/Lexeme.hpp"
#include "CircuitParsing/InputFileData.hpp"
#include "Circuit/NodeTypes.hpp"

namespace CircuitParsing {
  using std::function;
  using std::next;
  using std::prev;

  class CircuitParser {
  public:
      CircuitParser(LexemeStream input);
      virtual ~CircuitParser();

      InputFileData output;
  private:
      void parseInput(LexemeStream input);
      void parseLine(LexemeStream line);
      void parse_IS_A(LexemeStream line);
      void parse_IS_CONNECTED_TO(LexemeStream line);

      Lexeme& getLineOperator(LexemeStream line);

      vector<LexemeStream> splitInputToLines(LexemeStream input);
  };
}


#endif //OOPA_CIRCUITSIM_CIRCUITPARSER_HPP
