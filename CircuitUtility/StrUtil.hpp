//
// Created by mafn on 2/29/16.
//

#ifndef OOPA_CIRCUITSIM_STRUTIL_HPP
#define OOPA_CIRCUITSIM_STRUTIL_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

namespace CircuitUtility {
  //TODO: use proper using directives instead of pulling in the entirety of std
  using namespace std;

  class StrUtil {
  public:
      static vector<string> split(string str, char delim);
      static string removeSpaces(string str);
  };
};


#endif //OOPA_CIRCUITSIM_STRUTIL_HPP
