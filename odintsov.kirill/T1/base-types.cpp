#include "base-types.hpp"
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "shape.hpp"

void odintsov::movePoint(point_t& p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}

void odintsov::isoScalePoint(point_t& p, const point_t& anchor, double k)
{
  assertValidScaling(k);
  movePoint(p, (p.x - anchor.x) * (k - 1.0), (p.y - anchor.y) * (k - 1.0));
}

odintsov::rectangle_t odintsov::getFrameRectFromCorners(const point_t& bl, const point_t& tr)
{
  if (tr.x <= bl.x || tr.y <= bl.y) {
    throw std::invalid_argument("Corners set incorrectly");
  }
  return rectangle_t{tr.x - bl.x, tr.y - bl.y, {(bl.x + tr.x) * 0.5, (bl.y + tr.y) * 0.5}};
}

odintsov::point_t odintsov::getFrameRectBottomLeftCorner(const rectangle_t& rect)
{
  return point_t{rect.pos.x - rect.width * 0.5, rect.pos.y - rect.height * 0.5};
}

odintsov::point_t odintsov::getFrameRectTopRightCorner(const rectangle_t& rect)
{
  return point_t{rect.pos.x + rect.width * 0.5, rect.pos.y + rect.height * 0.5};
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
    leftX = std::min(points[i].x, leftX);
    rightX = std::max(points[i].x, rightX);
    bottomY = std::min(points[i].y, bottomY);
    topY = std::max(points[i].y, topY);
  }
  return getFrameRectFromCorners(point_t{leftX, bottomY}, point_t{rightX, topY});
}

std::ostream& odintsov::outputFrameRect(std::ostream& out, const rectangle_t& rect)
{
  point_t bl = getFrameRectBottomLeftCorner(rect);
  point_t tr = getFrameRectTopRightCorner(rect);
  return out << bl.x << ' ' << bl.y << ' ' << tr.x << tr.y;
}

bool odintsov::isPointInRectangle(const point_t& p, const rectangle_t& rect)
{
  point_t bl = getFrameRectBottomLeftCorner(rect);
  point_t tr = getFrameRectTopRightCorner(rect);
  return bl.x <= p.x && p.x <= tr.x && bl.y <= p.y && p.y <= tr.y;
}
