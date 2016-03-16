//
// Created by mafn on 3/14/16.
//

#include "InputFileData.hpp"

namespace CircuitParsing {
  InputFileData::InputFileData() {};
  InputFileData::~InputFileData() {};

  InputFileNode* InputFileData::getNode(string name) {
      for(InputFileNode& node : this->nodes) {
          if (node.name == name) {
              return &node;
          }
      }

      return nullptr;
  }
};