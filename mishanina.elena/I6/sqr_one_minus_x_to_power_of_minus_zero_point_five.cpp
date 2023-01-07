#include "sqr_one_minus_x_to_power_of_minus_zero_point_five.h"

double raiseToPower(double x, int power)
{
  if (power == 0)
  {
    return 1;
  }
  double result = 1;
  for (int i = 0; i < power; i++)
  {
    result *= x;
  }
  return result;
}

double numerator(int currentMember)
{
  double result = 1;
  int i = 1;
  int k = currentMember - 1;
  while (k != 0)
  {
    result *= i;
    i += 2;
    k--;
  }
  return result;
}

double znam(int currentMember)
{
  double result = 1;
  int i = 2;
  int k = currentMember - 1;
  while (k != 0)
  {
    result *= i;
    i += 2;
    k--;
  }
  return result;
}

double sqrtOneMinusXToPowerOfMinusZeroPointFive(double x, unsigned members, double error)
{
  double result = 0.0;
  int power = 2;
  int i = 1;
  while (i != members + 1)
  {
    if (i == 1)
    {
      result += 1.0;
    }
    else
    {
      result += numerator(i) / znam(i) * raiseToPower(x, power);
      power += 2;
    }
    i++;
  }
  return result;
}
