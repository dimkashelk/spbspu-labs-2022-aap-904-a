#include "base-types.h"
#include <cmath>

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
//  if (A.x < B.x && A.x < C.x && C.x < B.x && A.y == B.y && A.y > C.y && B.y > C.y)
  point_t pos{ (A.x + C.x) / 2, (A.y + C.y) / 2 };
  point_t D{ 2 * pos.x - B.x, 2 * pos.y - B.y };
  double AO = std::sqrt(std::pow(pos.x - A.x, 2) + std::pow(pos.y - A.y, 2));
  double OC = std::sqrt(std::pow(pos.x - C.x, 2) + std::pow(pos.y - C.y, 2));
  double BO = std::sqrt(std::pow(pos.x - B.x, 2) + std::pow(pos.y - B.y, 2));
  double OD = std::sqrt(std::pow(pos.x - D.x, 2) + std::pow(pos.y - D.y, 2));
  if (AO == OC && BO == OD)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isCorrectTriangle(const point_t& A, const point_t& B, const point_t& C)
{
  double ab_side = std::sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
  double ac_side = std::sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
  double bc_side = std::sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
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
