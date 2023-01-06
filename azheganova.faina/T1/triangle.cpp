#include "triangle.h"
#include "base_types.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

Triangle::Triangle():
  triangle1{point_t{0.0, 0.0}, point_t{0.0, 0.0}, point_t{0.0, 0.0}}
{}

Triangle::Triangle(point_t pos1, point_t pos2, point_t pos3):
  triangle1{pos1, pos2, pos3}
{
  double side1 = pow((pow((pos2.x - pos1.x), 2) + pow((pos2.y-pos1.y), 2 )), 0.5);
  double side2 = pow((pow((pos3.x - pos2.x), 2) + pow((pos2.y-pos2.y), 2 )), 0.5);
  double side3 = pow((pow((pos1.x - pos3.x), 2) + pow((pos1.y-pos3.y), 2 )), 0.5);
  if (((side3 + side2) <= side1) || ((side2 + side1) <= side3) || ((side3 + side1) <= side2))
  {
    throw std::invalid_argument("wrong triangle");
  }
}

double Triangle::getArea() const
{
  double firstpart = 0.0;
  double secondpart = 0.0;
  firstpart = (triangle1[1].x - triangle1[0].x) * (triangle1[2].y - triangle1[0].y);
  secondpart = (triangle1[2].x - triangle1[0].x) * (triangle1[1].y - triangle1[0].y);
  return std::abs(0.5 * (firstpart - secondpart));
}
rectangle_t Triangle::getFrameRect() const
{
  double maxx = std::max(triangle1[0].x, std::max(triangle1[1].x, triangle1[2].x));
  double maxy = std::max(triangle1[0].y, std::max(triangle1[1].y, triangle1[2].y));
  double minx = std::min(triangle1[0].x, std::min(triangle1[1].x, triangle1[2].x));
  double miny = std::min(triangle1[0].y, std::min(triangle1[1].y, triangle1[2].y));
  return makeFrame(point_t{minx, miny}, point_t{maxx, maxy});
}
point_t Triangle::findCenterOfTriangle()
{
  double pos1 = (triangle1[0].x + triangle1[1].x + triangle1[2].x) / 3;
  double pos2 = (triangle1[0].y + triangle1[1].y + triangle1[2].y) / 3;
  return (point_t {pos1, pos2});
}
void Triangle::move(point_t point)
{
  point_t center = findCenterOfTriangle();
  move(point.x - center.x, point.y - center.y);
}
void Triangle::move(double dx, double dy)
{
  triangle1[0].x += dx;
  triangle1[0].y += dy;
  triangle1[1].x += dx;
  triangle1[1].y += dy;
  triangle1[2].x += dx;
  triangle1[2].y += dy;
}
void Triangle::scale(double k) noexcept
{
  point_t center = findCenterOfTriangle();
  triangle1[0].x = k * (triangle1[0].x - center.x) + center.x;
  triangle1[1].x = k * (triangle1[1].x - center.x) + center.x;
  triangle1[2].x = k * (triangle1[2].x - center.x) + center.x;
  triangle1[0].y = k * (triangle1[0].y - center.y) + center.y;
  triangle1[1].y = k * (triangle1[1].y - center.y) + center.y;
  triangle1[2].y = k * (triangle1[2].y - center.y) + center.y;
}

Shape* Triangle::clone() const
{
  Triangle *copy = new Triangle(triangle1[0], triangle1[1], triangle1[2]);
  return copy;
}
