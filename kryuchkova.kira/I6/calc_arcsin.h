#include <cmath>
#include <stdexcept>

class TaylorTerm
{
  public:
    TaylorTerm(double x);
    double operator()();
  private:
    double x;
    double numerator;
    int denominator;
    size_t number;
};

TaylorTerm::TaylorTerm(double x):
  x(x),
  numerator(x),
  denominator(1),
  number(0)
{}

double TaylorTerm::operator()()
{
  if (number == 0)
  {
    number++;
    return x;
  }
  else if (number == 1)
  {
    numerator *= x * x;
    denominator = 6;
    number++;
    return numerator / denominator;
  }
  else
  {
    numerator *= (number * 2 - 1) * x * x;
    denominator *= (number * 2) / (number * 2 + 1);
    number++;
    return numerator / denominator;
  }
}

double calcArcsin(double x, double error, size_t max_number)
{
  TaylorTerm TaylorTerm(x);
  double term = 0;
  double res = 0;
  size_t counter = 0;
  do
  {
    term = TaylorTerm();
    res += term;
    counter++;
  }
  while (counter < max_number && term > error);
  return res;
}
