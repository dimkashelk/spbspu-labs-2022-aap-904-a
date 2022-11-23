#include <limits>
#include <stdexcept>

void max_DelBezOst_foo(unsigned int& max_DelBezOst, const int p1, const int  p2)
{

  if (p1 != 0 and p2 % p1 == 0)
  {
    if (max_DelBezOst == std::numeric_limits< unsigned int >::max())
    {
      throw std::overflow_error("too many val");
    }
    max_DelBezOst++;
  }
}
