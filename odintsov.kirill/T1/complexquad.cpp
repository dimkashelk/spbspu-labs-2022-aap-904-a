#include "complexquad.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "triangle.hpp"
#include "line.hpp"
#include "nearlyEquals.hpp"

odintsov::ComplexQuad::ComplexQuad(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4):
  p1(p1),
  p2(p2),
  p3(p3),
  p4(p4)
{
  point_t ip = getIntersectionPoint();
  const double e = 0.00001;
  if (nearlyEquals(ip, p1, e) || nearlyEquals(ip, p2, e) || nearlyEquals(ip, p3, e) || nearlyEquals(ip, p4, e)) {
    throw std::invalid_argument("points set incorrectly");
  }
}

double odintsov::ComplexQuad::getArea() const
{
  point_t ip = getIntersectionPoint();
  return getTriangleArea(p1, p4, ip) + getTriangleArea(p2, p3, ip);
}

odintsov::rectangle_t odintsov::ComplexQuad::getFrameRect() const
{
  point_t points[4] = {p1, p2, p3, p4};
  return getFrameRectFromPoints(points, 4);
}

void odintsov::ComplexQuad::move(double dx, double dy)
{
  movePoint(p1, dx, dy);
  movePoint(p2, dx, dy);
  movePoint(p3, dx, dy);
  movePoint(p4, dx, dy);
}

void odintsov::ComplexQuad::move(const point_t& pos)
{
  point_t middle = getMiddlePoint();
  move(pos.x - middle.x, pos.y - middle.y);
}

void odintsov::ComplexQuad::scale(double k)
{
  point_t middle = getMiddlePoint();
  isoScalePoint(p1, middle, k);
  isoScalePoint(p2, middle, k);
  isoScalePoint(p3, middle, k);
  isoScalePoint(p4, middle, k);
}

odintsov::point_t odintsov::ComplexQuad::getMiddlePoint() const
{
  return getIntersectionPoint();
}

odintsov::point_t odintsov::ComplexQuad::getIntersectionPoint() const
{
  return getLineSegIntersectionPoint(p1, p2, p3, p4);
}

odintsov::ComplexQuad* odintsov::ComplexQuad::clone() const
{
  return new ComplexQuad(p1, p2, p3, p4);
}
