//
// Created by mafn on 3/21/16.
//

#ifndef OOPA_CIRCUITSIM_OBSERVED_HPP
#define OOPA_CIRCUITSIM_OBSERVED_HPP

#include <vector>

#include "Circuit/Observer.hpp"

namespace Circuit {
  using std::vector;

  class Observer;

  class Observed {
  public:
      void attachObserver(Observer* toAttach);
      void notifyObservers();
  private:
      vector<Observer*>observers;
  };
}


#endif //OOPA_CIRCUITSIM_OBSERVED_HPP
