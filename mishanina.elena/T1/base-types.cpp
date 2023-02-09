#include "base-types.h"

double twoPointsDistance(const point_t& p1, const point_t& p2)
{
  double line_x = p1.x - p2.x;
  double line_y = p1.y - p2.y;
  return std::sqrt(line_x * line_x + line_y * line_y);
}

point_t getCenterRectangle(const point_t& ld_point, const point_t& ru_point)
{
  return point_t{ (ru_point.x + ld_point.x) / 2, (ru_point.y + ld_point.y) / 2 };
}

point_t getCenterParallelogram(const point_t& lu_point, const point_t& rd_point)
{
  return { (lu_point.x + rd_point.x) / 2, (lu_point.y + rd_point.y) / 2 };
}

bool isCorrectRectangle(const point_t& ld_point, const point_t& ru_point)
{
  if (ld_point.x < ru_point.x && ld_point.y < ru_point.y)
  {
    return true;
  }
  else
  {
    return false;
  }
}

point_t movePoint(const point_t point, const point_t dpoint)
{
  return point_t{ point.x + dpoint.x, point.y + dpoint.y };
}

bool isCorrectParallelogram(const point_t& A, const point_t& B, const point_t& C)
{
  if ((A.x == B.x && A.y == B.y) || (A.x == C.x && A.y == C.y) || (C.x == B.x && C.y == B.y) || (A.y != B.y && B.y != C.y))
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool isCorrectTriangle(const point_t& A, const point_t& B, const point_t& C)
{
  double ab_side = getSide(A, B);
  double ac_side = getSide(A, C);
  double bc_side = getSide(C, B);
  if (ab_side + ac_side > bc_side && ab_side + bc_side > ac_side && ac_side + bc_side > ab_side)
  {
    return true;
  }
  else
  {
    return false;
  }
}

point_t getCenterTriangle(const point_t& A, const point_t& B, const point_t& C)
{
  return { (A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3 };
}

point_t scalePoint(const point_t point, const point_t pos, const double k)
{
  double dx = (point.x - pos.x) * k;
  double dy = (point.y - pos.y) * k;
  point_t dpoint{ dx, dy };
  return movePoint(pos, dpoint);
}

double getSide(const point_t& p1, const point_t& p2)
{
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}
