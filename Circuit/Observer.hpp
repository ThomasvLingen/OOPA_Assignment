//
// Created by mafn on 3/21/16.
//

#ifndef OOPA_CIRCUITSIM_OBSERVER_HPP
#define OOPA_CIRCUITSIM_OBSERVER_HPP

#include "Circuit/Observed.hpp"

namespace Circuit {
  class Observed;

  class Observer {
  public:
      void observe(Observed& target);
      virtual void update()=0;
  private:
  };
}


#endif //OOPA_CIRCUITSIM_OBSERVER_HPP
