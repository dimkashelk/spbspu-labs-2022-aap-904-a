#include "concave.hpp"
#include <stdexcept>
#include "line.hpp"
#include "triangle.hpp"
#include "base-types.hpp"

odintsov::Concave::Concave(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4):
  p1(p1),
  p2(p2),
  p3(p3),
  p4(p4)
{
  if (!(isTriangle(p1, p2, p3) && isPointStrictlyInsideTriangle(p4, p1, p2, p3))) {
    throw std::invalid_argument("points are set incorrectly");
  }
}

double odintsov::Concave::getArea() const
{
  return getTriangleArea(p1, p4, p2) + getTriangleArea(p1, p4, p3);
}

odintsov::rectangle_t odintsov::Concave::getFrameRect() const
{
  constexpr unsigned short pointsAmt = 4;
  point_t points[pointsAmt] = {p1, p2, p3, p4};
  return getFrameRectFromPoints(points, pointsAmt);
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
  isoScalePoint(p1, middle, k);
  isoScalePoint(p2, middle, k);
  isoScalePoint(p3, middle, k);
  isoScalePoint(p4, middle, k);
}

odintsov::point_t odintsov::Concave::getMiddlePoint() const
{
  return p4;
}

odintsov::Concave* odintsov::Concave::clone() const
{
  return new Concave(p1, p2, p3, p4);
}
