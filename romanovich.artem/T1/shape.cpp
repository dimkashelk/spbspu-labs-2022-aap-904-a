#include "shape.h"
#include <stdexcept>
void Shape::tryScale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling koeff.");
  }
  scale(k);
}
