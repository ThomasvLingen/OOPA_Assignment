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

      // TODO: transform ':' into the more specific 'IS_A' and 'IS_CONNECTED_TO' tokens
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
}