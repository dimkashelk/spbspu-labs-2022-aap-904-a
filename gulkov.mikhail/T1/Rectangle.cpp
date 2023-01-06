#include "Rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(point_t one, point_t two):
  rect_({{(one.x + two.x) / 2, (one.y + two.y) / 2}, two.x - one.x, two.y - one.y})
{
  if (rect_.width <= 0.0 || rect_.height <= 0.0)
  {
    throw std::invalid_argument("Bad input, invalid rectangle size");
  }
}

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(point_t position)
{
  rect_.pos = position;
}

void Rectangle::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}