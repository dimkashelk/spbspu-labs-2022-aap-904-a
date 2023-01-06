#include "base-types.hpp"
#include <cstddef>
#include <stdexcept>
#include "minmax.hpp"

void odintsov::movePoint(point_t& p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}

void odintsov::isoScalePoint(const point_t& anchor, point_t& p, double k)
{
  movePoint(p, (p.x - anchor.x) * (k - 1.0), (p.y - anchor.y) * (k - 1.0));
}

odintsov::rectangle_t odintsov::getFrameRectFromPoints(const point_t* points, size_t amt)
{
  if (amt <= 1) {
    throw std::invalid_argument("Too little points for rectangle");
  }
  double leftX = points[0].x;
  double rightX = points[0].x;
  double bottomY = points[0].y;
  double topY = points[0].y;
  for (size_t i = 1; i < amt; i++) {
    leftX = min(points[i].x, leftX);
    rightX = max(points[i].x, rightX);
    bottomY = min(points[i].y, bottomY);
    topY = max(points[i].y, topY);
  }
  return rectangle_t{rightX - leftX, topY - bottomY, {(leftX + rightX) * 0.5, (bottomY + topY) * 0.5}};
}

bool odintsov::isPointInRectangle(const point_t& p, const rectangle_t& rect)
{
  return rect.pos.x - rect.width * 0.5 <= p.x && p.x <= rect.pos.x + rect.width * 0.5 &&
         rect.pos.y - rect.height * 0.5 <= p.y && p.y <= rect.pos.y + rect.height * 0.5;
}
