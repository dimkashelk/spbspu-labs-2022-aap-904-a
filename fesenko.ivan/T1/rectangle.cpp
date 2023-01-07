#include "rectangle.h"
#include <stdexcept>
#include "base-types.h"

Rectangle::Rectangle(const point_t &point1, const point_t &point2):
  rect{point2.x - point1.x, point2.y - point1.y, {(point1.x + point2.x) / 2, (point1.y + point2.y) / 2}}
{
  if (point1.x >= point2.x || point1.y >= point2.y) {
    throw std::invalid_argument("Wrong rectangle input\n");
  }
}

double Rectangle::getArea() const
{
  return rect.width * rect.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect;
}

void Rectangle::move(double dx, double dy)
{
  rect.pos.x += dx;
  rect.pos.y += dy;
}

void Rectangle::move(const point_t &pos)
{
  rect.pos = pos;
}

void Rectangle::scale(double k)
{
  if (k <= 0) {
    throw std::invalid_argument("Ratio must be greater then 0\n");
  }
  rect.width *= k;
  rect.height *= k;
}
