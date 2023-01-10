#include "shape.h"
#include <iostream>

void Shape::checkScale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("error");
  }
  scale(k);
}