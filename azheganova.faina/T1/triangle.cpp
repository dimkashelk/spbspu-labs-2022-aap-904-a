#include "triangle.h"
#include <iostream>

double side(point_t pos1, point_t pos2)
{
  double s = pow((pow((pos2.x - pos1.x), 2) + pow((pos2.y - pos1.y), 2 )), 0.5);
  return s;
}

Triangle::Triangle(point_t pos1, point_t pos2, point_t pos3):
  triangle1{pos1, pos2, pos3}
{
  double side1 = side(pos1, pos2);
  double side2 = side(pos2, pos3);
  double side3 = side(pos3, pos1);
  if (((side3 + side2) <= side1) || ((side2 + side1) <= side3) || ((side3 + side1) <= side2))
  {
    throw std::invalid_argument("wrong triangle");
  }
}

double Triangle::getArea() const
{
  double firstpart = (triangle1[1].x - triangle1[0].x) * (triangle1[2].y - triangle1[0].y);
  double secondpart = (triangle1[2].x - triangle1[0].x) * (triangle1[1].y - triangle1[0].y);
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
  for (size_t i = 0; i < 3; i++)
  {
    triangle1[i].x = k * (triangle1[i].x - center.x) + center.x;
    triangle1[i].y = k * (triangle1[i].y - center.y) + center.y;
  }
}

Shape* Triangle::clone() const
{
  Triangle *copy = new Triangle(triangle1[0], triangle1[1], triangle1[2]);
  return copy;
}
