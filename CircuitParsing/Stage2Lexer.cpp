//
// Created by mafn on 3/6/16.
//

#include "Stage2Lexer.hpp"

namespace CircuitParsing {
  Stage2Lexer::Stage2Lexer(LexemeStream input) {
      this->output = input;

      this->replaceIdentifyers();
  }

  Stage2Lexer::~Stage2Lexer() {};

  void Stage2Lexer::replaceIdentifyers() {
      this->setDescriptors();
      this->setNodeIdentifyers();

      for(LexemeStream::iterator it = this->output.begin(); it != this->output.end(); it++) {
          if((*it).type == LexemeType::COLON) {
              this->transformColon(it);
          }
      }
  }

  void Stage2Lexer::setDescriptors() {
      for(Lexeme& lexeme: this->output) {
          if (lexeme.type == LexemeType::IDENTIFYER) {
              this->setDescriptor(lexeme);
          }
      }
  }

  void Stage2Lexer::setDescriptor(Lexeme& lexeme) {
      for(LexemeType descriptorType : pool.descriptors) {
          if (this->pool.isDescriptor(descriptorType, lexeme.value)) {
              lexeme = Lexeme(descriptorType, "");
              return;
          }
      }
  }

  void Stage2Lexer::setNodeIdentifyers() {
      for(Lexeme& lexeme: this->output) {
          if (lexeme.type == LexemeType::IDENTIFYER) {
              setNodeIdentifyer(lexeme);
          }
      }
  }

  void Stage2Lexer::setNodeIdentifyer(Lexeme &lexeme) {
      lexeme = Lexeme(LexemeType::NODE_IDENTIFYER, lexeme.value);
  }

  void Stage2Lexer::transformColon(LexemeStream::iterator colon) {
      LexemeStream::iterator nextLexeme = next(colon, 1);
      LexemeStream::iterator previousLexeme = prev(colon, 1);

      if (nextLexeme != this->output.end() && previousLexeme != this->output.end()) {
          if (this->isISA(*previousLexeme, *nextLexeme)) {
              *colon = Lexeme(LexemeType::IS_A, "");
          } else if (this->isISConnectedTo(*previousLexeme, *nextLexeme)) {
              *colon = Lexeme(LexemeType::IS_CONNECTED_TO, "");
          }
      }
  }

  bool Stage2Lexer::isISA(Lexeme previous, Lexeme next) {
      bool previousIsNodeIdentifyer = previous.type == LexemeType::NODE_IDENTIFYER;
      bool nextIsDescriptor = this->pool.isDescriptor(next.type);

      return previousIsNodeIdentifyer && nextIsDescriptor;
  }

  bool Stage2Lexer::isISConnectedTo(Lexeme previous, Lexeme next) {
      return previous.type == LexemeType::NODE_IDENTIFYER && next.type == LexemeType::NODE_IDENTIFYER;
  }
}