//
// Created by mafn on 3/16/16.
//

#ifndef OOPA_CIRCUITSIM_PARSINGEXCEPTIONS_HPP
#define OOPA_CIRCUITSIM_PARSINGEXCEPTIONS_HPP

#include <exception>
#include <iostream>

namespace CircuitParsing {
  using std::exception;

  class InputFileEdgeUnknownNodeException : public exception {
      virtual const char* what() const throw() {
          return "In an edge description, an unknown node is used";
      }
  };

  class InputFileEdgeSyntaxError : public exception {
      virtual const char* what() const throw() {
          return "In an edge description, there was a syntax error. Edge description syntax should be: [NODE]:[NODE],[NODE]...";
      }
  };
}

#endif //OOPA_CIRCUITSIM_PARSINGEXCEPTIONS_HPP
