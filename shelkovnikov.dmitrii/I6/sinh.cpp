#include "sinh.h"
#include <cmath>
#include <stdexcept>
#include <iomanip>
Sinh::Sinh(double x):
  x(x)
{}
double Sinh::operator()()
{
  if (x >= 1 || x <= -1)
  {
    throw std::out_of_range("X must be in (-1; 1)");
  }
  double res = 0;
  double summand = x;
  unsigned count_summand = 1;
  long factorial = 1;
  long counter = 1;
  while (std::fabs(summand) > error && count_summand < count)
  {
    res += summand;
    x *= x * x;
    factorial *= (counter + 1) * (counter + 2);
    counter += 2;
    count_summand++;
    summand = x / static_cast< double >(factorial);
  }
  if (count_summand >= count && abs(summand) > error)
  {
    throw std::out_of_range("The specified accuracy has not been reached");
  }
  return res;
}
void print_row(std::ostream &out, double x, double error, unsigned k)
{
  out << std::fixed << std::setfill(' ') << std::setw(5) << std::setprecision(2);
  out << x << ' ';
  Sinh sinh(x);
  sinh.error = error;
  sinh.count = k;
  try
  {
    out << sinh();
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
