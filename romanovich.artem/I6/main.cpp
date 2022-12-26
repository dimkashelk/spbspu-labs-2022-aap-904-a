#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <stddef.h>
#include "printtable.h"

size_t myFactorial(size_t a)
{
  size_t result = 1;
  while (a > 0)
  {
    result *= a;
    a--;
  }
  return result;
}

double myPow(double a, size_t power)
{
  double result = 1;
  for (size_t i = 0; i < power; ++i)
  {
    result *= a;
  }
  return result;
}

bool isSmaller(double a, double b, double epsilon) {
  double absA = std::abs(a);
  double absB = std::abs(b);
  double diff = std::abs(a - b);
  double minDouble = std::numeric_limits< double >::min();
  if (a < b)
  {
    return true;
  } 
  if (a == 0 || b == 0 || diff < minDouble)
  {
    return diff < (epsilon * minDouble);
  }
  else
  {
    return diff / (absA + absB) < epsilon;
  }
}

double mySinh(double x, double absError, size_t numberMax)
{
  double result = 0;
  size_t numberSummand = 0;
  while (numberSummand <= numberMax)
  {
    double nextSummand = myPow(x, 1 + 2 * numberSummand) / myFactorial(1 + 2 * numberSummand);
    numberSummand++;
    if (isSmaller(std::abs(nextSummand), absError, 1e-6))
    {
      return result;
    }
    result += nextSummand;
  }
  throw std::invalid_argument("Invalid max summands number.");
}

int main()
{
  double test = 0.8;
  printTable(std::cout, -1, 1, 0.1, test, 1e-4, 10);
}
