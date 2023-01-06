#include "triangle.h"
#include "base_types.h"
#include <iostream>
#include <stdexcept>

Triangle::Triangle()
{}

Triangle::Triangle(point_t pos1, point_t pos2, point_t pos3):
  triangle1{pos1, pos2, pos3}
{}

Triangle::Triangle(const Triangle &tmp):
  triangle1{tmp.triangle1[0], tmp.triangle1[1], tmp.triangle1[2]}
{}
Triangle::Triangle(Triangle &&tmp):
  triangle1{tmp.triangle1[0], tmp.triangle1[1], tmp.triangle1[2]}
{}

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
  double pos2 = (triangle1[0].y + triangle1[1].y + triangle1[2].y) / 2;
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
void Triangle::scale(double k)
{
  if (k <= 0)
  {
    std::cout << "incorrect value";
  }
  else
  {
  point_t center = findCenterOfTriangle();
  triangle1[0].x = k * (triangle1[0].x - center.x) + center.x;
  triangle1[1].x = k * (triangle1[1].x - center.x) + center.x;
  triangle1[2].x = k * (triangle1[2].x - center.x) + center.x;
  }
}

Shape* Triangle::clone() const
{
  Triangle *copy = new Triangle(triangle1[0], triangle1[1], triangle1[2]);
  return copy;
}
