#include "supportFunctions.h"
#include <algorithm>
#include <stdexcept>

void movePoint(point_t &p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}

void movePointBecauseOfScale(point_t &p, point_t &zoomCenter, double k)
{
  if (k <= 0) {
    throw std::invalid_argument("Ratio must be greater then 0\n");
  }
  movePoint(p, (p.x - zoomCenter.x) * (k - 1), (p.y - zoomCenter.y) * (k - 1));
}

bool isIntersectionOfSegments(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4)
{
  point_t p1, p2, p3, p4;
  if (point1.x < point2.x) {
    p1 = point1;
    p2 = point2;
  } else {
    p1 = point2;
    p2 = point1;
  }
  if (point3.x < point4.x) {
    p3 = point3;
    p4 = point4;
  } else {
    p3 = point4;
    p4 = point3;
  }
  if (p2.x < p3.x) {
    return false;
  }
  if (p1.x - p2.x == 0 && p3.x - p4.x == 0) {
    return false;
  }
  if (p1.x - p2.x == 0) {
    double xa = p1.x;
    double a2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b2 = p3.y - a2 * p3.x;
    double ya = a2 * xa + b2;
    if (p3.x <= xa && p4.x >= xa && std::min(p1.y, p2.y) <= ya && std::max(p1.y, p2.y) >= ya) {
      return true;
    }
    return false;
  }
  if (p3.x - p4.x == 0) {
    double xa = p3.x;
    double a1 = (p1.y - p2.y) / (p1.x - p2.x);
    double b1 = p1.y - a1 * p1.x;
    double ya = a1 * xa + b1;
    if (p1.x <= xa && p2.x >= xa && std::min(p3.y, p4.y) <= ya && std::max(p3.y, p4.y) >= ya) {
      return true;
    }
    return false;
  }
  double a1 = (p1.y - p2.y) / (p1.x - p2.x);
  double a2 = (p3.y - p4.y) / (p3.x - p4.x);
  double b1 = p1.y - a1 * p1.x;
  double b2 = p3.y - a2 * p3.x;
  if (a1 == a2) {
    return false;
  }
  double xa = (b2 - b1) / (a1 - a2);
  if (xa < std::max(p1.x, p3.x) || xa > std::min(p2.x, p4.x)) {
    return false;
  } else {
    return true;
  }
}
point_t getIntersectionPoint(const point_t &point1, const point_t &point2, const point_t &point3, const point_t &point4)
{
  point_t p1, p2, p3, p4;
  double x0 = 0.0, y0 = 0.0;
  if (point1.x < point2.x) {
    p1 = point1;
    p2 = point2;
  } else {
    p1 = point2;
    p2 = point1;
  }
  if (point3.x < point4.x) {
    p3 = point3;
    p4 = point4;
  } else {
    p3 = point4;
    p4 = point3;
  }
  if (p1.x - p2.x == 0) {
    x0 = p1.x;
    double a2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b2 = p3.y - a2 * p3.x;
    y0 = a2 * x0 + b2;
  } else if (p3.x - p4.x == 0) {
    x0 = p3.x;
    double a1 = (p1.y - p2.y) / (p1.x - p2.x);
    double b1 = p1.y - a1 * p1.x;
    y0 = a1 * x0 + b1;
  } else {
    double a1 = (p1.y - p2.y) / (p1.x - p2.x);
    double a2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b1 = p1.y - a1 * p1.x;
    double b2 = p3.y - a2 * p3.x;
    x0 = (b2 - b1) / (a1 - a2);
    y0 = (x0 - p1.x) * a1 + p1.y;
  }
  return {x0, y0};
}

