#include "concave.hpp"
#include <stdexcept>
#include "triangle.hpp"
#include "base-types.hpp"
#include "minmax.hpp"

odintsov::Concave::Concave(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4):
  p1(p1),
  p2(p2),
  p3(p3),
  p4(p4)
{
  if (!isTriangle(p1, p2, p3) || !isPointInsideTriangle(p4, p1, p2, p3)) {
    throw std::invalid_argument("points are set incorrectly");
  }
}

double odintsov::Concave::getArea() const
{
  return getTriangleArea(p1, p4, p2) + getTriangleArea(p1, p4, p3);
}

odintsov::rectangle_t odintsov::Concave::getFrameRect() const
{
  double leftX = min(p1.x, p2.x, p3.x, p4.x);
  double rightX = max(p1.x, p2.x, p3.x, p4.x);
  double bottomY = min(p1.y, p2.y, p3.y, p4.y);
  double topY = max(p1.y, p2.y, p3.y, p4.y);
  return rectangle_t{rightX - leftX, topY - bottomY, {(leftX + rightX) * 0.5, (bottomY + topY) * 0.5}};
}

void odintsov::Concave::move(double dx, double dy)
{
  movePoint(p1, dx, dy);
  movePoint(p2, dx, dy);
  movePoint(p3, dx, dy);
  movePoint(p4, dx, dy);
}

void odintsov::Concave::move(const point_t& pos)
{
  point_t middle = getMiddlePoint();
  move(pos.x - middle.x, pos.y - middle.y);
}

void odintsov::Concave::scale(double k)
{
  point_t middle = getMiddlePoint();
  isoScalePoint(middle, p1, k);
  isoScalePoint(middle, p2, k);
  isoScalePoint(middle, p3, k);
  isoScalePoint(middle, p4, k);
}

odintsov::point_t odintsov::Concave::getMiddlePoint() const
{
  return p4;
}
