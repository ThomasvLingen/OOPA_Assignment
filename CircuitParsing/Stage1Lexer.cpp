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

      if (!line.empty()) {
          string currentIdentifyer = "";

          for(string::iterator currentChar = line.begin(); currentChar != line.end(); currentChar++) {
              if (this->currentCharIsLexeme(currentChar, LexemeType::IDENTIFYER)) {
                  currentIdentifyer += *currentChar;

                  // If the next character is not part of an identifyer whilst the current one is, it's the end of an identifyer!
                  if(!this->nextCharIsLexeme(currentChar, LexemeType::IDENTIFYER)){
                      lexed_line.push_back(Lexeme(LexemeType::IDENTIFYER, currentIdentifyer));

                      currentIdentifyer = "";
                  }
              }

              for(CircuitParsing::LexemeType lexemeType : pool.SingleCharLexemes) {
                  if (this->currentCharIsLexeme(currentChar, lexemeType)) {
                      lexed_line.push_back(Lexeme(lexemeType, ""));
                  }
              }
          }
      }

      return lexed_line;
  };

  bool Stage1Lexer::currentCharIsLexeme(string::iterator currentChar, LexemeType type) {
      return pool.isLexeme(type, *currentChar);
  }

  bool Stage1Lexer::nextCharIsLexeme(string::iterator currentChar, LexemeType type) {
      return pool.isLexeme(type, *next(currentChar, 1));
  }

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
