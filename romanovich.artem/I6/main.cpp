#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <stddef.h>

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

void printTableRow(std::ostream & out, double x, double absError, size_t numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << mySinh(x, absError, numberMax) << " ";
  out << std::setw(10) << std::setprecision(5) << sinh(x) << "\n";
}

void printTable(double left, double right, double step, double x, double absError, size_t numberMax)
{
  if (left > right)
  {
    double tmp = left;
    left = right;
    right = tmp;
  }
  for (double value=left; value <= right; value += step)
  {
    if (isSmaller(std::abs(value), step/10, 1e-6))
    {
      value = 0;
    }
    printTableRow(std::cout, value, absError, numberMax);
  }
}

int main()
{
  double test = 0.8;
  printTable(-1, 1, 0.1, test, 1e-4, 10);
}
