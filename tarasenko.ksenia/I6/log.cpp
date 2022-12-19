#include <cmath>
#include <stdexcept>
#include "pow.hpp"

double ln(double x, double absError, unsigned numberMax)
{
  if (x <= 2 || x >= 3)
  {
    throw std::invalid_argument("x out the interval (2; 3)");
  }
  double sum = 0;
  double member = 0;
  unsigned number = 1;
  do
  {
    member = 2 / ((2 * number - 1) * pow(x, 2 * number - 1));
    sum += member;
    number++;
  }
  while(number <= numberMax && std::abs(member) > absError);
  if (number >= numberMax && std::abs(member) > absError)
  {
    throw "accuracy not achieved";
  }
  return sum;
}
