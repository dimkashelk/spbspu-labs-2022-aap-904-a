#include "rectangle.h"
#include <stdexcept>
Rectangle::Rectangle(const point_t &A, const point_t &C):
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
  return getFrameRect().height * getFrameRect().width;
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
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  multiplyVector(center, &a_, k);
  multiplyVector(center, &c_, k);
}
Shape *Rectangle::clone() const
{
  return new Rectangle(a_, c_);
}
bool Rectangle::goodRectangleInput() const
{
  return (a_.x < c_.x && a_.y < c_.y);
}
