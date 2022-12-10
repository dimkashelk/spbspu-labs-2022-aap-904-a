#include "sinh.h"
#include <cmath>
#include <stdexcept>
double sinh(double x, double error, unsigned count)
{
  if (x >= 1 || x <= -1)
  {
    throw std::out_of_range("X must be in (-1; 1)");
  }
  double res = 0;
  double summand = x;
  unsigned count_summand = 1;
  long factorial = 1;
  long counter = 1;
  while (std::fabs(summand) > error && count_summand < count)
  {
    res += summand;
    x *= x * x;
    factorial *= (counter + 1) * (counter + 2);
    counter += 2;
    count_summand++;
    summand = x / static_cast< double >(factorial);
  }
  if (count_summand > count && abs(summand) > error)
  {
    throw std::out_of_range("The specified accuracy has not been reached");
  }
  if (count_summand < count && abs(summand) < error)
  {
    throw std::out_of_range("Fewer terms than required");
  }
  return res;
}
