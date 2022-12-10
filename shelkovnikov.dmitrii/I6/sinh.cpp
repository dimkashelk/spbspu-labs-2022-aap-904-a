#include "sinh.h"
#include <cmath>
double sinh(double x, double error, unsigned count)
{
  double res = x;
  unsigned count_summand = 1;
  long factorial = 1;
  long counter = 1;
  do
  {
    x *= x * x;
    factorial *= (counter + 1) * (counter + 2);
    counter += 2;
    count_summand++;
    res += x / static_cast< double >(factorial);
  }
  while (abs(x) >= error && count_summand <= count);
}
