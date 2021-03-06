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
  using std::string;
  using std::vector;

  class StrUtil {
  public:
      static vector<string> split(string str, char delim);
      static string removeSpaces(string str);
  };
};


#endif //OOPA_CIRCUITSIM_STRUTIL_HPP
