#include "sinh.h"
#include <cmath>
#include <stdexcept>
#include <iomanip>
Sinh::Sinh(double x):
  x(x),
  factorial(1),
  number(1)
{
  if (x >= 1 || x <= -1)
  {
    throw std::out_of_range("X must be in (-1; 1)");
  }
}
double Sinh::operator()()
{
  x *= x * x;
  factorial *= (number + 1) * (number + 2);
  number += 2;
  return x / factorial;
}
double sinh(double x, double error, unsigned k)
{
  Sinh sinh(x);
  double res = 0;
  double summand = x;
  unsigned count_summand = 1;
  while (std::fabs(summand) > error && count_summand < k)
  {
    res += summand;
    count_summand++;
    summand = sinh();
  }
  if (count_summand >= k && abs(summand) > error)
  {
    throw std::out_of_range("The specified accuracy has not been reached");
  }
  return res;
}
void print_row(std::ostream &out, double x, double error, unsigned k)
{
  out << std::fixed << std::setfill(' ') << std::setw(5) << std::setprecision(2);
  out << x << ' ';
  try
  {
    out << sinh(x, error, k);
  }
  catch (const std::out_of_range &e)
  {
    out << e.what();
  }
}
void print_table(std::ostream &out, double left, double right, double step, double error, unsigned k)
{
  if (left > right)
  {
    throw std::out_of_range("Right more then left");
  }
  for (; left <= right; left += step)
  {
    print_row(out, left, error, k);
    out << '\n';
  }
}
