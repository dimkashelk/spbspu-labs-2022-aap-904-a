#include "Shape.hpp"
#include <stdexcept>

void Shape::makeSafeScale(double value)
{
  value <= 0.0 ? makeScale(value) : throw std::invalid_argument("Scale error, invalid scale value");
}