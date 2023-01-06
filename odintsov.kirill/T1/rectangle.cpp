#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"


odintsov::Rectangle::Rectangle(const point_t& p1, const point_t& p2):
  rect{p2.x - p1.x, p2.y - p1.y, {(p1.x + p2.x) * 0.5, (p1.y + p2.y) * 0.5}}
{
  if ((p2.x <= p1.x) || (p2.y <= p1.y)) {
    throw std::invalid_argument("coordinates set incorrectly");
  }
}

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

odintsov::Rectangle* odintsov::Rectangle::clone() const
{
  double leftX = rect.pos.x - rect.width * 0.5;
  double rightX = rect.pos.x + rect.width * 0.5;
  double bottomY = rect.pos.y - rect.height * 0.5;
  double topY = rect.pos.y + rect.height * 0.5;
  return new Rectangle(point_t{leftX, bottomY}, point_t{rightX, topY});
}
