#include "rectangle.h"
#include <cmath>
dimkashelk::Rectangle::Rectangle(rectangle_t rectangle):
  rectangle_(rectangle)
{}
dimkashelk::Rectangle::Rectangle(point_t point_1, point_t point_2):
  rectangle_(point_1, point_2)
{}
dimkashelk::Rectangle::Rectangle(const Rectangle &rect):
  rectangle_(rect.rectangle_)
{}
dimkashelk::Rectangle::Rectangle(Rectangle &&rect):
  rectangle_(rect.rectangle_)
{}
dimkashelk::Rectangle &dimkashelk::Rectangle::operator=(const Rectangle &other)
{
  rectangle_ = other.rectangle_;
  return *this;
}
dimkashelk::Rectangle &dimkashelk::Rectangle::operator=(Rectangle &&tmp) noexcept
{
  rectangle_ = tmp.rectangle_;
  return *this;
}
double dimkashelk::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}
dimkashelk::rectangle_t dimkashelk::Rectangle::getFrameRect() const
{
  return rectangle_;
}
void dimkashelk::Rectangle::move(point_t point)
{
  rectangle_.point = point;
}
void dimkashelk::Rectangle::move(double delta_x, double delta_y)
{
  rectangle_.point.x += delta_x;
  rectangle_.point.y += delta_y;
}
void dimkashelk::Rectangle::scale(double k)
{
  rectangle_.width *= std::fabs(k);
  rectangle_.height *= std::fabs(k);
}
dimkashelk::Shape *dimkashelk::Rectangle::clone() const
{
  return new Rectangle(rectangle_);
}
