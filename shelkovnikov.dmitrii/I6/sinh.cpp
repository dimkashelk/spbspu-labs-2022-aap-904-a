#include "sinh.h"
#include <cmath>
double sinh(double x, double error, unsigned count)
{
  double res = x;
  double summand = 0;
  unsigned count_summand = 1;
  long factorial = 1;
  long counter = 1;
  do
  {
    x *= x * x;
    factorial *= (counter + 1) * (counter + 2);
    counter += 3;
    count_summand++;
    summand = x / static_cast< double >(factorial);
    res += summand;
  }
  while (abs(summand) > error && count_summand < count);
  return res;
}