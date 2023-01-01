#include "rectangle.h"
#include <cmath>
Rectangle::Rectangle(rectangle_t rectangle):
  rectangle_(rectangle)
{}
Rectangle::Rectangle(point_t point_1, point_t point_2):
  rectangle_(point_1, point_2)
{}
Rectangle::Rectangle(const Rectangle &rect):
  rectangle_(rect.rectangle_)
{}
Rectangle::Rectangle(Rectangle &&rect):
  rectangle_(rect.rectangle_)
{}
Rectangle &Rectangle::operator=(const Rectangle &other)
{
  rectangle_ = other.rectangle_;
  return *this;
}
Rectangle &Rectangle::operator=(Rectangle &&tmp) noexcept
{
  rectangle_ = tmp.rectangle_;
  return *this;
}
double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}
void Rectangle::move(point_t point)
{
  rectangle_.point = point;
}
void Rectangle::move(double delta_x, double delta_y)
{
  rectangle_.point.x += delta_x;
  rectangle_.point.y += delta_y;
}
void Rectangle::scale(double k)
{
  rectangle_.width *= std::fabs(k);
  rectangle_.height *= std::fabs(k);
}
Shape *Rectangle::clone() const
{
  return new Rectangle(rectangle_);
}
