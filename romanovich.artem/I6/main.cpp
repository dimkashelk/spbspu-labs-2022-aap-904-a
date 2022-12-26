#include "iostream"
#include <stddef.h>

size_t factorial(size_t a)
{
  size_t result = 1;
  while (a > 0)
  {
    result *= a;
    a--;
  }
  return result;
}

size_t pow(size_t a, size_t power)
{
  size_t result = 1;
  for (size_t i = 0; i < power; ++i)
  {
    result *= a;
  }
  return result;
}

double sinh(double x, double absError, unsigned long numberMax)
{
  double result = 0;
  size_t precision = 10;
  for (size_t i = 0; i < precision; ++i)
  {
    result += pow(x, 1+2*i)/factorial(1+2*i);
  }
  return result;
}



//корректное сравнение double


int main()
{
  std::cout << sinh(1, 0, 0) << "\n";
}