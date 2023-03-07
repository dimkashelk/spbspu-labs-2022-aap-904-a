#include "shenanigans.h"
#include <iomanip>

double term2::operator()()
{
  index += 2;
  value = value * x * x * (index - 2) / index;
  return value;
}

term2::term2(double x, double value):
  x(x),
  value(value),
  index(1)
{}

double getCustomArth(double x, double error, size_t maxNum)
{
  term2 getNext(x, x);
  double res = 0;
  double curr = x;
  size_t cnt = 0;

  while (std::abs(curr) >= error) {
    cnt++;
    if (cnt > maxNum) {
      throw std::runtime_error("Expected accuracy could not be achieved");
    }
    res += curr;
    curr = getNext();
  }
  return res;
}

double term1::operator()()
{
  index += 2;
  value = -value * x * x / (index - 1) / index;
  return value;
}

term1::term1(double x):
  x(x),
  value(1),
  index(0)
{}

double getCustomCos(double x, double error, size_t maxNum)
{
  term1 getNext(x);
  double res = 0;
  double curr = 1;
  size_t cnt = 0;

  while (std::abs(curr) >= error) {
    cnt++;
    if (cnt > maxNum) {
      throw std::runtime_error("Expected accuracy could not be achieved");
    }
    res += curr;
    curr = getNext();
  }
  return res;
}

void printRow(std::ostream& stream, double x, double res1, double res2)
{
  stream << std::setw(5) << std::setprecision(5) << x << "  ";
  stream << std::setw(7) << res1 << "  ";
  stream << std::setw(7) << std::cos(x) << "  ";

  stream << std::setw(7) << res2 << "  ";
  stream << std::setw(7) << std::atanh(x) << '\n';
}

void printTable(std::ostream& stream, double lb, double rb, double error, size_t maxNum, double step)
{
  for (double i = lb; i <= rb; i += step) {
    printRow(stream, i, getCustomCos(i, error, maxNum), getCustomArth(i, error, maxNum));
  }
}
