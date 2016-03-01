//
// Created by mafn on 2/28/2016.
//

#include "Stage1Lexer.hpp"

namespace CircuitParsing {
  void Stage1Lexer::addToOutput(LexemeStream toAdd) {
      this->output.insert(this->output.end(), toAdd.begin(), toAdd.end());
  };

  Stage1Lexer::Stage1Lexer(string filename) {
      ifstream fileHandler(filename, ifstream::in);

      string line;
      while (getline(fileHandler, line)) {
          this->addToOutput(this->lexLine(line));
      }
  };

  LexemeStream Stage1Lexer::lexLine(string line) {
      LexemeStream lexed_line;
      line = this->removeComments(line);
      line = CircuitUtility::StrUtil::removeSpaces(line);

      // TODO: refactor this disgusting crap
      if (!line.empty()) {
          string currentIdentifyer = "";

          for(string::iterator currentChar = line.begin(); currentChar != line.end(); currentChar++) {
              if (Lexeme::isLexeme(LexemeType::IDENTIFYER, *currentChar)) {
                  char nextChar = *next(currentChar, 1);
                  currentIdentifyer += *currentChar;

                  if(!Lexeme::isLexeme(LexemeType::IDENTIFYER, nextChar)){
                      lexed_line.push_back(Lexeme(LexemeType::IDENTIFYER, currentIdentifyer));

                      currentIdentifyer = "";
                  }
              }

              for(LexemeType lexemeType : {LexemeType::SEMICOLON, LexemeType::COLON, LexemeType::COMMA }) {
                  if (Lexeme::isLexeme(lexemeType, *currentChar)) {
                      lexed_line.push_back(Lexeme(lexemeType, ""));
                  }
              }
          }
      }

      return lexed_line;
  };

  string Stage1Lexer::removeComments(string line) {
      size_t commentIndex = line.find('#');

      if (commentIndex != string::npos) {
          return line.substr(0, commentIndex);
      } else {
          return line;
      }
  };

  Stage1Lexer::~Stage1Lexer() {};
}
