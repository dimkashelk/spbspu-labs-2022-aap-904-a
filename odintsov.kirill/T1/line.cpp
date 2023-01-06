#include "line.hpp"
#include <stdexcept>
#include "base-types.hpp"

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
  point_t l1[2] = {p1, p2};
  point_t l2[2] = {p3, p4};
  if(!(isPointInRectangle(ip, getFrameRectFromPoints(l1, 2)) && isPointInRectangle(ip, getFrameRectFromPoints(l2, 2)))) {
    throw std::invalid_argument("Line segments do not intersect");
  }
  return ip;
}
