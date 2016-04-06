//
// Created by mafn on 4/6/16.
//

#ifndef OOPA_CIRCUITSIM_CIRCUITSIMULATOR_HPP
#define OOPA_CIRCUITSIM_CIRCUITSIMULATOR_HPP

#include <vector>
#include <string>

#include "CircuitParsing/Stage1Lexer.hpp"
#include "CircuitParsing/Stage2Lexer.hpp"
#include "CircuitParsing/CircuitParser.hpp"
#include "Circuit/CircuitVisitors/CircuitVisitor.hpp"
#include "Circuit/Circuit.hpp"


namespace Circuit {
  using std::vector;
  using std::string;

  typedef vector<CircuitVisitors::CircuitVisitor*> CircuitPlugins;

  class CircuitSimulator {
  public:
      CircuitSimulator(string inputFilePath, CircuitPlugins plugins);
      virtual ~CircuitSimulator();

  private:
      CircuitPlugins plugins;
      Circuit* circuit;

      Circuit* parseInputFile(string inputFilePath);
      void printPhaseMessage(bool start, string phaseName);
      void runPlugins();
  };
}


#endif //OOPA_CIRCUITSIM_CIRCUITSIMULATOR_HPP
