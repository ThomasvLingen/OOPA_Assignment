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

  void CircuitParser::parse_IS_CONNECTED_TO(LexemeStream line) {
      for(LexemeStream::iterator it=line.begin(); it != line.end(); it++) {
          if ((*it).type == LexemeType::IS_CONNECTED_TO) {
              Lexeme origin = *(prev(it, 1));
              InputFileNode* originNode = this->output.getNode(origin.value);

              if (originNode) {
                  this->output.edges[originNode] = this->getInputFileNodeEdges(LexemeStream(it+1, line.end()));
              } else {
                  throw InputFileEdgeUnknownNodeException();
              }
          }
      }
  };

  InputFileNodeStream CircuitParser::getInputFileNodeEdges(LexemeStream edges) {
      InputFileNodeStream nodeStream;
      LexemeType currentExpectedType = LexemeType::NODE_IDENTIFYER;

      for(LexemeStream::iterator it_lexeme = edges.begin(); it_lexeme != edges.end(); it_lexeme++) {
          if ((*it_lexeme).type == currentExpectedType) {
              if (currentExpectedType == LexemeType::NODE_IDENTIFYER) {
                  InputFileNode* currentNode = this->output.getNode((*it_lexeme).value);

                  if (currentNode) {
                      nodeStream.push_back(currentNode);
                  } else {
                      throw InputFileEdgeUnknownNodeException();
                  }

                  currentExpectedType = LexemeType::COMMA;
              } else if (currentExpectedType == LexemeType::COMMA) {
                  currentExpectedType = LexemeType::NODE_IDENTIFYER;
              }
          } else {
              throw InputFileEdgeSyntaxError();
          }
      }

      return nodeStream;
  }

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