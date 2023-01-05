#include "rectangle.hpp"
#include "base-types.hpp"

odintsov::Rectangle::Rectangle(double x, double y, double width, double height):
  rect{width, height, {x, y}}
{}

odintsov::Rectangle::Rectangle(const point_t& pos, double width, double height):
  rect{width, height, pos}
{}

odintsov::Rectangle::Rectangle(const rectangle_t& rect):
  rect(rect)
{}

double odintsov::Rectangle::getArea() const
{
  return rect.width * rect.height;
}

odintsov::rectangle_t odintsov::Rectangle::getFrameRect() const
{
  return rect;
}

void odintsov::Rectangle::move(double dx, double dy)
{
  rect.pos.x += dx;
  rect.pos.y += dy;
}

void odintsov::Rectangle::move(const point_t& pos)
{
  rect.pos = pos;
}

void odintsov::Rectangle::scale(double k)
{
  rect.width *= k;
  rect.height *= k;
}
