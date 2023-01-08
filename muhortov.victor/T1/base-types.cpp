#include "base-types.hpp"
#include <cmath>

double calculatePointsDistance(const point_t &p1, const point_t &p2)
{
  double line_x = p1.x - p2.x;
  double line_y = p1.y - p2.y;
  return std::sqrt(line_x * line_x + line_y * line_y);
}

double findDeltaScale(double x, scale_t scale)
{
  return (x - scale.pos.x) * scale.scale;
}

point_t calculateVectorSum(point_t position, double delta_x, double delta_y)
{
  position.x += delta_x;
  position.y += delta_y;
  return position;
}

point_t calculateVectorDifference(point_t position, double delta_x, double delta_y)
{
  position.x -= delta_x;
  position.y -= delta_y;
  return position;
}

point_t calculateScale(point_t position, point_t center, double k)
{
  position.x = k * (position.x - center.x) + center.x;
  position.y = k * (position.y - center.y) + center.y;
  return position;
}

point_t moveToDelta(point_t position, double delta_x, double delta_y)
{
  position.x += delta_x;
  position.y += delta_y;
  return position;
}

double calculateTriangleArea(const double &a, const double &b, const double &c)
{
  double p = (a + b + c) / 2;
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double calculateSideForTriangle(const point_t &one, const point_t &two)
{
  return std::sqrt((two.x - one.x) * (two.x - one.x) + (two.y - one.y) * (two.y - one.y));
}

bool checkingSideForPosition(const point_t &one, const point_t &two, const point_t &four)
{
  return ((one.x - four.x) * (two.y - one.y) - (two.x - one.x) * (one.y - four.y)) > 0;
}

bool checkingTriangle(const point_t &one, const point_t &two, const point_t &three)
{
  double a = calculateSideForTriangle(three, one);
  double b = calculateSideForTriangle(two, one);
  double c = calculateSideForTriangle(three, two);
  return a + b < c || a + c < b || b + c < a;
}

bool checkingPosition(const point_t &one, const point_t &two, const point_t &three, const point_t &four)
{
  bool trOne = checkingSideForPosition(one, two, four);
  bool trTwo = checkingSideForPosition(two, three, four);
  bool trThree = checkingSideForPosition(three, one, four);;
  return !((trOne && trTwo && trThree) || (!trOne && !trTwo && !trThree));
}

bool checkingConcave(const point_t &one, const point_t &two, const point_t &three, const point_t &four)
{
  return (checkingTriangle(one, two, three) || one.x == four.x || one.y == four.y || checkingPosition(one, two, three, four));
}
