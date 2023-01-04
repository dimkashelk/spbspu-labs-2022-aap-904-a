#include "triangle.h"
#include "base_types.h"
#include <iostream>
#include <stdexcept>

triangle::triangle()
{}

triangle::triangle(point_t pos1, point_t pos2, point_t pos3):
  triangle1{pos1, pos2, pos3}
{}

triangle::triangle(const triangle &tmp):
  triangle1{tmp.triangle1[0], tmp.triangle1[1], tmp.triangle1[2]}
{}
triangle::triangle(triangle &&tmp):
  triangle1{tmp.triangle1[0], tmp.triangle1[1], tmp.triangle1[2]}
{}
double triangle::getArea() const
{
  double firstpart = 0.0;
  double secondpart = 0.0;
  firstpart = (triangle1[2].x - triangle1[1].x) * (triangle1[3].y - triangle1[1].y);
  secondpart = (triangle1[3].x - triangle1[1].x) * (triangle1[2].y - triangle1[1].y);
  return std::fabs(0.5 * (firstpart - secondpart));
}
rectangle_t triangle::getFrameRect() const
{
  double maxx = std::max(triangle1[0].x, std::max(triangle1[1].x, triangle1[2].x));
  double maxy = std::max(triangle1[0].y, std::max(triangle1[1].y, triangle1[2].y));
  double minx = std::min(triangle1[0].x, std::min(triangle1[1].x, triangle1[2].x));
  double miny = std::min(triangle1[0].y, std::min(triangle1[1].y, triangle1[2].y));
  rectangle_t fortriangle(point_t {(minx + maxx) / 2}, point_t {(maxy + miny) / 2});
  return fortriangle;
}
point_t triangle::findCenterOfTriangle()
{
  double pos1 = (triangle1[0].x + triangle1[1].x + triangle1[2].x) / 3;
  double pos2 = (triangle1[0].y + triangle1[1].y + triangle1[2].y) / 2;
  return (point_t {pos1, pos2});
}
void triangle::move(point_t point)
{
  point_t center = findCenterOfTriangle();
  move(point.x - center.x, point.y - center.y);
}
void triangle::move(double dx, double dy)
{
  triangle1[0].x += dx;
  triangle1[0].y += dy;
  triangle1[1].x += dx;
  triangle1[1].y += dy;
  triangle1[2].x += dx;
  triangle1[2].y += dy;
}
void triangle::scale(double k)
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

shape* triangle::clone() const
{
  triangle *copy = new triangle(triangle1[0], triangle1[1], triangle1[2]);
  return copy;
}
