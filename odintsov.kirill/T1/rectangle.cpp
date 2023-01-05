#include "rectangle.hpp"
#include <stdexcept>
#include "base-types.hpp"


odintsov::Rectangle::Rectangle(double leftX, double bottomY, double rightX, double topY):
  rect{rightX - leftX, topY - bottomY, {(leftX + rightX) * 0.5, (bottomY + topY) * 0.5}}
{
  if ((rightX <= leftX) || (topY <= bottomY)) {
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
