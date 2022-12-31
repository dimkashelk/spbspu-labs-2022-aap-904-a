#include "rectangle.h"
Rectangle::Rectangle():
  rectangle_(0.0, 0.0, 0.0, 0.0)
{}
Rectangle::Rectangle(rectangle_t rectangle):
  rectangle_(rectangle)
{}
Rectangle::Rectangle(double x1, double y1, double x2, double y2):
  rectangle_(x1, y1, x2, y2)
{
  if (!(x1 < x2 && y1 < y2))
  {
    throw std::logic_error("It isn't a rectangle");
  }
}
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
  rectangle_.width *= k;
  rectangle_.height *= k;
}
Shape *Rectangle::clone() const
{
  return new Rectangle(rectangle_);
}
