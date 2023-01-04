#include "shape.hpp"
#include <stdexcept>

void tarasenko::Shape::checkCoefficient(double k) const
{
  if (k <= 0)
  {
    throw std::invalid_argument("the coefficient is less than zero");
  }
}