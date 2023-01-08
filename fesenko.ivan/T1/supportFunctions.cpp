#include "supportFunctions.h"
#include <algorithm>

void movePoint(point_t &p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}

void movePointBecauseOfScale(point_t &p, point_t &zoomCenter, double k)
{
  movePoint(p, (p.x - zoomCenter.x) * (k - 1), (p.y - zoomCenter.y) * (k - 1));
}

bool isIntersectionOfSegments(point_t &p1, point_t &p2, point_t &p3, point_t &p4)
{
  if (p2.x < p1.x) { //Очень плохая идея менять местами, но пока работает только так
    point_t tmp = p1;
    p1 = p2;
    p2 = tmp;
  }
  if (p4.x < p3.x) {
    point_t tmp = p3;
    p3 = p4;
    p4 = tmp;
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
  }
  else {
    return true;
  }
}
