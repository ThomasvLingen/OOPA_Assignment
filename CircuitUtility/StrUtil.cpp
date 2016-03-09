//
// Created by mafn on 2/29/16.
//

#include "StrUtil.hpp"

namespace CircuitUtility {
  vector<string> StrUtil::split(string str, char delim) {
      string copy = str;
      vector<string> tokens;

      size_t delimPosition = 0;

      while(copy.find(delim) != string::npos || delimPosition != string::npos){
          delimPosition = copy.find(delim);

          string token = copy.substr(0, delimPosition);
          // Check if the token isn't empty, if not, push it!
          if(!token.empty()){
              tokens.push_back(token);
          }

          // Substract added token from our string
          copy = copy.substr(delimPosition + 1);
      }

      return tokens;
  };

  string StrUtil::removeSpaces(string str) {
      string copy = str;

      // For some reason, isspace has to be resolved from the global scope.
      copy.erase(remove_if(copy.begin(), copy.end(), ::isspace), copy.end());

      return copy;
  };
}

