//
// Created by mafn on 3/21/16.
//

#include "Observed.hpp"

namespace Circuit{
  void Observed::attachObserver(Observer* toAttach) {
      this->observers.push_back(toAttach);
  }

  void Observed::notifyObservers() {
      for(Observer* observer : this->observers) {
          observer->update();
      }
  }
}