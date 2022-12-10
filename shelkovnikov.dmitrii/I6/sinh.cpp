#include "sinh.h"
#include <cmath>
#include <stdexcept>
double sinh(double x, double error, unsigned count)
{
  if (x >= 1 || x <= -1)
  {
    throw std::out_of_range("X must be in (-1; 1)");
  }
  double res = x;
  double summand = 0;
  unsigned count_summand = 1;
  long factorial = 1;
  long counter = 1;
  do
  {
    x *= x * x;
    factorial *= (counter + 1) * (counter + 2);
    counter += 2;
    count_summand++;
    summand = x / static_cast< double >(factorial);
    res += summand;
  }
  while (abs(summand) > error && count_summand < count);
  if (count_summand > count)
  {
    throw std::out_of_range("The specified accuracy has not been reached");
  }
  return res;
}
