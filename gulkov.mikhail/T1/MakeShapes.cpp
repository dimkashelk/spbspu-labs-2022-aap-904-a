#include "MakeShapes.hpp"
#include <stdexcept>
#include "Rectangle.hpp"
#include "Ellipse.hpp"
#include "Concave.hpp"

Shape *makeRectangle(std::istream &input)
{
  double dots[4]{0.0, 0.0, 0.0, 0.0};
  input >> dots[0] >> dots[1] >> dots[2] >> dots[3];
  return new Rectangle({dots[0], dots[1]}, {dots[2], dots[3]});
}

Shape *makeEllipse(std::istream &input)
{
  double dots[4]{0.0, 0.0, 0.0, 0.0};
  input >> dots[0] >> dots[1] >> dots[2] >> dots[3];
  return new Ellipse({dots[0], dots[1]}, dots[2], dots[3]);
}

Shape *makeConcave(std::istream &input)
{
  double dots[8]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  input >> dots[0] >> dots[1] >> dots[2] >> dots[3] >> dots[4] >> dots[5] >> dots[6] >> dots[7];
  return new Concave({dots[0], dots[1]}, {dots[2], dots[3]}, {dots[4], dots[5]}, {dots[6], dots[7]});
}

scale_t getScale(std::istream &input)
{
  double dots[3]{0.0, 0.0, 0.0};
  input >> dots[0] >> dots[1] >> dots[2];
  if (dots[2] < 0.0)
  {
    throw std::invalid_argument("invalid scale size");
  }
  return {{dots[0], dots[1]}, dots[2]};
}
