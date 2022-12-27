#include "sinh.h"
#include <stdexcept>
#include "comparedoubles.h"
NextSinhElMultiplier::NextSinhElMultiplier(double x):
  x(x),
  numberSummand(0)
{
}
double NextSinhElMultiplier::operator()()
{
  //return x * myPow(x, 2 * numberSummand) / static_cast< double >(myFactorial(2 * numberSummand));
  numberSummand++;
  if (numberSummand == 1)
  {
    return x;
  }
  else
  {
    return x * x * x / static_cast< double >((numberSummand) * (numberSummand + 1));
  }
}
double countSinh(double x, double absError, size_t numberMax)
{
  double result = 0;
  size_t numberSummand = 0;
  NextSinhElMultiplier nextSinhElMultiplier(x);
  double nextSummand = 1;
  while (numberSummand <= numberMax)
  {
    //double nextSummand = nextSinhElMultiplier();
    nextSummand *= nextSinhElMultiplier();
    //nextSinhElMultiplier.numberSummand++;
    numberSummand++;
    if (isSmaller(std::abs(nextSummand), absError, 1e-6))
    {
      return result;
    }
    result += nextSummand;
  }
  throw std::invalid_argument("Invalid max summands number.");
}
