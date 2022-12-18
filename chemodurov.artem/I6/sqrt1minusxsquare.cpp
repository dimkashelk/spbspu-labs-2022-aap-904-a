#include "sqrt1minusxsquare.h"
#include <stdexcept>

double Sqrt1MinusXSquare::operator()(double x, size_t max_members, double error)
{
  if (members == max_members && current > error)
  {
    throw std::runtime_error("Accuracy was not achieved");
  }
  double res = 0.0;
  if (!members)
  {
    current = 1;
    res += current;
    members++;
  }
  do
  {
    if (members == max_members && current > error)
    {
      throw std::runtime_error("Accuracy was not achieved");
    }
    double next = current * x * x * (2 * members - 1) / (2 * members);
    res += next;
    current = next;
    members++;
  }
  while (current <= error);
  members = 0;
  return res;
}
