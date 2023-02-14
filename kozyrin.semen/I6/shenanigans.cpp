#include "shenanigans.h"

double unsign(double n)
{
  if (n < 0) {
    return -n;
  }
  return n;
}

double term::operator()()
{
  n += 2;
  value = -value * x * x / (n - 1) / n;
  return value;
}

double customCos(double x, double error, size_t maxNum)
{
  term getNext{x};
  double res = 0;
  double curr = 1;
  size_t cnt = 0;

  while (unsign(curr) >= error) {
    cnt++;
    if (cnt > maxNum) {
      throw std::runtime_error("Expected accuracy could not be achieved");
    }
    res += curr;
    curr = getNext();
  }
}