#include <iostream>
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

double mySinh(double x, double absError, size_t numberMax)
{
  double result = 0;
  size_t numberSummand = 0;
  while (numberSummand <= numberMax)
  {
    double nextSummand = myPow(x, 1 + 2 * numberSummand) / myFactorial(1 + 2 * numberSummand);
    numberSummand++;
    if (nextSummand < absError) //корректное сравнение double
    {
      return result;
    }
    result += nextSummand;
    std::cout << nextSummand << "\n";
  }
  throw std::invalid_argument("Invalid max summands number.");
}


int main()
{
  double test = 0.8;
  std::cout << mySinh(test, 0.001, 100) << "\n";
  std::cout << sinh(test) << "\n";
}