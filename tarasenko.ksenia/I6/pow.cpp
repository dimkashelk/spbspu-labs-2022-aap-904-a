#include "pow.hpp"

double pow(double x, unsigned n)
{
  double res = 1.0;
  if (n != 0)
  {
    for (unsigned i = 1; i <= n; i++)
    {
      res = res * x;
    }
  }
  return res;
}
