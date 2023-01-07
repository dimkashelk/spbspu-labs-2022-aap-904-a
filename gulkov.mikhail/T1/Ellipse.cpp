#include "Ellipse.hpp"
#include <stdexcept>

Ellipse::Ellipse(point_t center, double radius1, double radius2):
  rect_({{center.x, center.y}, radius1 * 2.0, radius2 * 2.0}),
  r1_(radius1),
  r2_(radius2)
{
  if (rect_.width <= 0 || rect_.height <= 0)
  {
    throw std::invalid_argument("Bad input, invalid ellipse size");
  }
}

double Ellipse::getArea() const
{
  return 3.1415926535 * r1_ * r2_;
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
  r1_ *= value;
  r2_ *= value;
  rect_.width = r1_ * 2.0;
  rect_.height = r1_ * 2.0;
}

Shape *Ellipse::clone() const
{
  return new Ellipse(rect_.pos, r1_, r2_);
}
