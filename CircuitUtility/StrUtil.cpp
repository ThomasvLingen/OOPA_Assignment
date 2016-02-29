//
// Created by mafn on 2/29/16.
//

#include "StrUtil.hpp"

namespace CircuitUtility {
  vector<string> StrUtil::split(string str, char delim) {
      string tmp = str;
      vector<string> tokens;

      size_t delimPosition = 0;

      while(tmp.find(delim) != string::npos || delimPosition != string::npos){
          delimPosition = tmp.find(delim);

          string token = tmp.substr(0, delimPosition);
          // Check if the token isn't empty, if not, push it!
          if(!token.empty()){
              tokens.push_back(token);
          }

          // Remove added token from our string
          tmp = tmp.substr(delimPosition + 1);
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

