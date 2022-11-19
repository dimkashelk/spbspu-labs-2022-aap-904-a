#include <iostream>
#include <limits>

void max_Mono_foo(int& max_Mono, int& k, const int p1, const int p2)
{
  if (p1 != 0 and p2 > p1)
    {

    if (k == std::numeric_limits< unsigned int >::max())
    {
      throw std::overflow_error("too many val");
    }
  k++;
  if (max_Mono < k)
    max_Mono = k;
  }
  else
  {
    if (max_Mono < k)
      max_Mono = k;
    k = 0;
  }
}
