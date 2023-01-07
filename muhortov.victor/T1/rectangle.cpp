#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(point_t one, point_t two):
  rectangle({{(one.x + two.x) / 2.0, (one.y + two.y) / 2.0}, two.x - one.x, two.y - one.y})
{
  if (rectangle.width <= 0.0 || rectangle.height <= 0.0)
  {
    throw std::invalid_argument("Error: invalid rectangle size");
  }
}

double Rectangle::getArea()
{
  return rectangle.width * rectangle.height;
}

rectangle_t Rectangle::getFrameRect()
{
  return rectangle;
}

void Rectangle::move(point_t newpos)
{
  rectangle.pos = newpos;
}

void Rectangle::move(double delta_x, double delta_y)
{
  rectangle.pos.x += delta_x;
  rectangle.pos.y += delta_y;
}
