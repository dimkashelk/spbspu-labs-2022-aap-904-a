#include "minmax.hpp"

double odintsov::min(double a, double b)
{
  return a < b ? a : b;
}

double odintsov::min(double a, double b, double c)
{
  return min(min(a, b), c);
}

double odintsov::min(double a, double b, double c, double d)
{
  return min(min(a, b), min(c, d));
}

double odintsov::max(double a, double b)
{
  return a > b ? a : b;
}

double odintsov::max(double a, double b, double c)
{
  return max(max(a, b), c);
}

double odintsov::max(double a, double b, double c, double d)
{
  return max(max(a, b), max(c, d));
}
