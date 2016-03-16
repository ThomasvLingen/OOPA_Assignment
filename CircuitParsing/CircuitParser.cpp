//
// Created by mafn on 3/14/16.
//

#include "CircuitParser.hpp"

namespace CircuitParsing {
  CircuitParser::CircuitParser(LexemeStream input) {
      this->parseInput(input);
  }

  CircuitParser::~CircuitParser() {};

  void CircuitParser::parseInput(LexemeStream input) {
      vector<LexemeStream> lines = this->splitInputToLines(input);

      for(LexemeStream& line : lines) {
          this->parseLine(line);
      }
  }

  void CircuitParser::parseLine(LexemeStream line) {
      Lexeme lineOperator = this->getLineOperator(line);

      this->getParseFunction(lineOperator.type)(line);
  }

  CircuitParser::ParseFunction CircuitParser::getParseFunction(LexemeType operatorType) {
      map<LexemeType, ParseFunction> bar = {
              {LexemeType::IS_A, bind(mem_fn(&CircuitParser::parse_IS_A), this, std::placeholders::_1)},
              {LexemeType::IS_CONNECTED_TO, bind(mem_fn(&CircuitParser::parse_IS_CONNECTED_TO), this, std::placeholders::_1)}
      };

      return bar[operatorType];
  }

  void CircuitParser::parse_IS_A(LexemeStream line) {
      for(LexemeStream::iterator it=line.begin(); it != line.end(); it++) {
          if ((*it).type == LexemeType::IS_A) {
              Lexeme node = *(prev(it, 1));
              Lexeme descriptor = *(next(it, 1));

              this->output.nodes.push_back(
                  InputFileNode(Circuit::lexemeTypeToNodeType(descriptor.type), node.value)
              );
          }
      }
  }

  // TODO: actually implement this
  void CircuitParser::parse_IS_CONNECTED_TO(LexemeStream line) {};

  Lexeme& CircuitParser::getLineOperator(LexemeStream line) {
      for(Lexeme& lexeme : line) {
         if(lexeme.type == LexemeType::IS_A || lexeme.type == LexemeType::IS_CONNECTED_TO) {
             return lexeme;
         }
      }
  }

  vector<LexemeStream> CircuitParser::splitInputToLines(LexemeStream input) {
      vector<LexemeStream> lines = {};
      LexemeStream currentLine = {};

      for(LexemeStream::iterator it = input.begin(); it != input.end(); it++) {
          if ((*it).type != LexemeType::SEMICOLON) {
              currentLine.push_back(*it);
          } else {
              lines.push_back(currentLine);

              currentLine = {};
          }
      }

      return lines;
  };
};