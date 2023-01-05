#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"
#include "getDistance.hpp"

double min(double a, double b, double c)
{
  double minVal = a < b ? a : b;
  return c < minVal ? c : minVal;
}

double max(double a, double b, double c)
{
  double maxVal = a > b ? a : b;
  return c > maxVal ? c : maxVal;
}

odintsov::Triangle::Triangle(const point_t& p1, const point_t& p2, const point_t& p3):
  p1(p1),
  p2(p2),
  p3(p3)
{
  double a = getDistance(p1, p2);
  double b = getDistance(p1, p3);
  double c = getDistance(p2, p3);
  double maxSide = max(a, b, c);
  if (maxSide >= a + b + c - maxSide) {
    throw std::invalid_argument("triangle is set incorrectly");
  }
}

double odintsov::Triangle::getArea() const
{
  double a = getDistance(p1, p2);
  double b = getDistance(p1, p3);
  double c = getDistance(p2, p3);
  double s = (a + b + c) * 0.5;
  return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

odintsov::rectangle_t odintsov::Triangle::getFrameRect() const
{
  double leftX = min(p1.x, p2.x, p3.x);
  double rightX = max(p1.x, p2.x, p3.x);
  double bottomY = min(p1.y, p2.y, p3.y);
  double topY = max(p1.y, p2.y, p3.y);
  return rectangle_t{rightX - leftX, topY - bottomY, {(leftX + rightX) * 0.5, (bottomY + topY) * 0.5}};
}

void odintsov::Triangle::move(double dx, double dy)
{
  movePoint(p1, dx, dy);
  movePoint(p2, dx, dy);
  movePoint(p3, dx, dy);
}

void odintsov::Triangle::move(const point_t& pos)
{
  point_t middle = getMiddlePoint();
  move(pos.x - middle.x, pos.y - middle.y);
}

void odintsov::Triangle::scale(double k)
{
  point_t middle = getMiddlePoint();
  isoScalePoint(middle, p1, k);
  isoScalePoint(middle, p2, k);
  isoScalePoint(middle, p3, k);
}

odintsov::point_t odintsov::Triangle::getMiddlePoint() const
{
  return point_t{(p1.x + p2.x + p3.x) / 3.0, (p1.y + p2.y + p3.y) / 3.0};
}
