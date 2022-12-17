#include "sqrt1minusxsquare.h"

double Sqrt1MinusXSquare::operator()(size_t max_members, double error)
{
  if (members == max_members && next > error)
  {
    throw std::runtime_error("Accuracy was not achieved");
  }
  
  return 0.0;
}
