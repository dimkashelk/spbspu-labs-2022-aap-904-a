#include "sqrt1minusxsquare.h"
#include <stdexcept>

double Sqrt1MinusXSquare::operator()(size_t max_members, double error)
{
  if (members == max_members && current > error)
  {
    throw std::runtime_error("Accuracy was not achieved");
  }
  double next = 0.0d;
  current = next;
  members++;
  return next;
}
