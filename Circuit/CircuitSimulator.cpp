//
// Created by mafn on 4/6/16.
//

#include "CircuitSimulator.hpp"

namespace Circuit {
  CircuitSimulator::CircuitSimulator(string inputFilePath, CircuitPlugins plugins) {
      this->plugins = plugins;

      this->circuit = parseInputFile(inputFilePath);

      this->runPlugins();
  }

  CircuitSimulator::~CircuitSimulator() {
      delete[] this->plugins;
  }

  void CircuitSimulator::runPlugins() {
      for (CircuitVisitors::CircuitVisitor* plugin : this->plugins) {
          this->printPhaseMessage(true, plugin->name);

          try {
              this->circuit->accept(*plugin);
          } catch(string str) {
              cout << str << endl;
              exit(-1);
          }

          this->printPhaseMessage(false, plugin->name);
      }
  }

  Circuit* CircuitSimulator::parseInputFile(string inputFilePath) {
      this->printPhaseMessage(true, "STAGE 1 LEXING");
      CircuitParsing::Stage1Lexer   s1Lexer(inputFilePath);
      this->printPhaseMessage(false, "STAGE 1 LEXING");

      this->printPhaseMessage(true, "STAGE 2 LEXING");
      CircuitParsing::Stage2Lexer   s2Lexer(s1Lexer.output);
      this->printPhaseMessage(false, "STAGE 2 LEXING");

      this->printPhaseMessage(true, "PARSING");
      CircuitParsing::CircuitParser parser(s2Lexer.output);
      this->printPhaseMessage(false, "PARSING");

      return new Circuit(parser.output);
  }

  void CircuitSimulator::printPhaseMessage(bool start, string phaseName) {
      string startOrEnd;

      if (start) {
          startOrEnd = "START";
      } else {
          startOrEnd = "END";
      }

      cout << "[" + phaseName + "]" + " " + startOrEnd << endl;
  }
}