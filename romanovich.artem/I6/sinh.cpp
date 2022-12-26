#include "sinh.h"
#include <stdexcept>
#include "comparedoubles.h"
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
NextSinhEl::NextSinhEl(double x) :
  x(x),
  numberSummand(0)
{
}
double NextSinhEl::operator()()
{
  return x * myPow(x, 2 * numberSummand) / static_cast< double >(myFactorial(2 * numberSummand));
}
double countSinh(double x, double absError, size_t numberMax)
{
  double result = 0;
  NextSinhEl nextSinhEl(x);
  while (nextSinhEl.numberSummand <= numberMax)
  {
    double nextSummand = nextSinhEl();
    nextSinhEl.numberSummand++;
    if (isSmaller(std::abs(nextSummand), absError, 1e-6))
    {
      return result;
    }
    result += nextSummand;
  }
  throw std::invalid_argument("Invalid max summands number.");
}
