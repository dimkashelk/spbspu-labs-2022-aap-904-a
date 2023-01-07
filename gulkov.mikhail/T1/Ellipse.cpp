#include "Ellipse.hpp"
#include <stdexcept>

Ellipse::Ellipse(point_t center, double radius1, double radius2):
  rect_({{center.x, center.y}, radius1 * 2.0, radius2 * 2.0}),
  local_radius1(radius1),
  local_radius2(radius2)
{
  if (rect_.width <= 0 || rect_.height <= 0)
  {
    throw std::invalid_argument("Bad input, invalid ellipse size");
  }
}

double Ellipse::getArea() const
{
  return 3.1415926535 * local_radius1 * local_radius2;
}

rectangle_t Ellipse::getFrameRect() const
{
  return rect_;
}

void Ellipse::move(point_t position)
{
  rect_.pos = position;
}

void Ellipse::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}


void Ellipse::makeScale(double value)
{
  local_radius1 *= value;
  local_radius2 *= value;
  rect_.width = local_radius1 * 2.0;
  rect_.height = local_radius2 * 2.0;
}