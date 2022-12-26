#include <iostream>
#include <cmath>  
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

double mySinh(double x, double absError, unsigned long numberMax)
{
  double result = 0;
  size_t precision = 10;
  size_t numberSummand = 0;
  for (size_t i = 0; i < precision; ++i)
  {
    double nextSummand = myPow(x, 1 + 2 * i) / myFactorial(1 + 2 * i);
    numberSummand++;
    if (nextSummand < absError) //корректное сравнение double
    {
      return result;
    }
    if (numberSummand > numberMax)
    {
      //TODO: throw exception
    }
    result += nextSummand;
    std::cout << nextSummand << "\n";
  }
  return result;
}


int main()
{
  double test = 0.8;
  std::cout << mySinh(test, 0, 0) << "\n";
  std::cout << sinh(test) << "\n";
}