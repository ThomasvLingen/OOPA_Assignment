//
// Created by mafn on 3/22/2016.
//

#ifndef OOPA_CIRCUITSIM_CONSTRUCTOR_HPP
#define OOPA_CIRCUITSIM_CONSTRUCTOR_HPP

namespace CircuitUtility {
  template<class T, typename... Args>
  T* Constructor(Args... args) {
      return new T(args...);
  }
}

#endif //OOPA_CIRCUITSIM_CONSTRUCTOR_HPP
