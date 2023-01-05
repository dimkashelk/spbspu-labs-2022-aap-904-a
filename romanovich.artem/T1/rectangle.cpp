#include "rectangle.h"
#include <stdexcept>
Rectangle::Rectangle(const point_t & A, const point_t & C):
  a_(A),
  c_(C)
{
  if (!goodRectangleInput())
  {
    throw std::invalid_argument("Bad rectangle input.");
  }
}
double Rectangle::getArea() const
{
  return (c_.y - a_.y) * (c_.x - a_.x);
}
rectangle_t Rectangle::getFrameRect() const
{
  return {(c_.x + a_.x) / 2, (c_.y + a_.y) / 2, c_.x - a_.x, c_.y - a_.y};
}
void Rectangle::move(double dx, double dy)
{
  a_.x += dx;
  a_.y += dy;
  c_.x += dx;
  c_.y += dy;
}
void Rectangle::move(const point_t &position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling coeff.");
  }
  double centerX = getFrameRect().pos.x;
  double centerY = getFrameRect().pos.y;
  a_.x = k * (a_.x - centerX) + centerX;
  a_.y = k * (a_.y - centerY) + centerY;
  c_.x = k * (c_.x - centerX) + centerX;
  c_.y = k * (c_.y - centerY) + centerY;
}
Shape *Rectangle::clone() const
{
  return new Rectangle(a_, c_);
}
bool Rectangle::goodRectangleInput() const
{
  return (a_.x < c_.x && a_.y < c_.y);
}
