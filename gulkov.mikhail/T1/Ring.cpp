#include "Ring.hpp"
#include <stdexcept>

Ring::Ring(point_t center, double r1_v, double r1_h, double r2_v, double r2_h):
  rect_({{center.x, center.y}, r2_h * 2.0, r2_v * 2.0}),
  r1_v_(r1_v),
  r1_h_(r1_h),
  r2_v_(r2_v),
  r2_h_(r2_h)
{
  if (r1_v <= 0 || r1_h <= 0 || r2_v <= 0 || r2_h <= 0 || (r1_v == r2_v && r1_h == r2_h))
  {
    throw std::invalid_argument("Bad input, invalid ellipses radius's, => invalid ring");
  }
}

double Ring::getArea() const
{
  return (r2_v_ * r2_h_ * 3.141592653589793238) - (r1_v_ * r1_h_ * 3.141592653589793238);
}

rectangle_t Ring::getFrameRect() const
{
  return rect_;
}

void Ring::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}

void Ring::move(double delta_x, double delta_y)
{
  rect_.pos.x += delta_x;
  rect_.pos.y += delta_y;
}

void Ring::makeScale(double k)
{
  r1_v_ *= k;
  r1_h_ *= k;
  r2_v_ *= k;
  r2_h_ *= k;
  rect_.width = r2_v_ * 2.0;
  rect_.height = r2_h_ * 2.0;
}

Shape *Ring::clone() const
{
  return new Ring(rect_.pos, r1_v_, r1_h_, r2_v_, r2_h_);
}
