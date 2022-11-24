#include <iostream>
#include <stdexcept>
#include "elementsaftermax.h"
void ElementsAfterMax::operator()(int curr)
{
  constexpr unsigned int max_int = std::numeric_limits< unsigned >::max();
  while (curr!= 0)
  {
    cnt++;
    if (curr < max)
    {
       if (cnt == max_int)
       {
          throw std::overflow_error("Overflow\n");
       }
       else
       {
          cnt++;
       }
    }
    else
    {
       max = curr;
       cnt = 0;
    }
  }
}
