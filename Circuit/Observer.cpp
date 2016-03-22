//
// Created by mafn on 3/21/16.
//

#include "Observer.hpp"

namespace Circuit {
  void Observer::observe(Observed target) {
      target.attachObserver(this);
  }
}