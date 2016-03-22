//
// Created by mafn on 3/14/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUITPARSER_HPP
#define OOPA_CIRCUITSIM_CIRCUITPARSER_HPP

#include <functional>

#include "CircuitParsing/Lexeme.hpp"
#include "CircuitParsing/InputFileData.hpp"
#include "Circuit/NodeTypes.hpp"
#include "CircuitParsing/ParsingExceptions.hpp"

namespace CircuitParsing {
  using std::function;
  using std::next;
  using std::prev;
  using std::mem_fn;
  using std::bind;

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

      InputFileNodeStream getInputFileNodeEdges(LexemeStream edges);

      Lexeme* getLineOperator(LexemeStream line);
      typedef function<void(LexemeStream)> ParseFunction;
      ParseFunction getParseFunction(LexemeType operatorType);

      vector<LexemeStream> splitInputToLines(LexemeStream input);
  };
}


#endif //OOPA_CIRCUITSIM_CIRCUITPARSER_HPP
