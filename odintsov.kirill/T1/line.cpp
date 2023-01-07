#include "line.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"
#include "nearlyEquals.hpp"

double odintsov::getLineSegLength(const point_t& p1, const point_t& p2)
{
  return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

odintsov::point_t odintsov::getLineIntersectionPoint(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4)
{
  double Dx = (p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x);
  double Dy = (p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x);
  double D = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
  return point_t{Dx/D, Dy/D};
}

odintsov::point_t odintsov::getLineSegIntersectionPoint(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4)
{
  point_t ip = getLineIntersectionPoint(p1, p2, p3, p4);
  if(!(isPointOnLineSeg(ip, p1, p2) && isPointOnLineSeg(ip, p3, p4))) {
    throw std::invalid_argument("Line segments do not intersect");
  }
  return ip;
}

bool odintsov::isPointOnLineSeg(const point_t& p, const point_t& p1, const point_t& p2)
{
  point_t points[2] = {p1, p2};
  if (isPointInRectangle(p, getFrameRectFromPoints(points, 2))) {
    constexpr double epsilon = 0.00001;
    return nearlyEquals(getLineSegLength(p1, p2), getLineSegLength(p1, p) + getLineSegLength(p, p2), epsilon);
  }
  return false;
}
