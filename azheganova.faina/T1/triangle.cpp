#include "triangle.h"
#include <iostream>
#include <cmath>
#include "isoscale.h"

Shape* inputTriangle(std::istream &input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (!input)
  {
    throw std::logic_error("error");
  }
  return new Triangle(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3});
}

double findSide(point_t p1, point_t p2)
{
  return pow((pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)), 0.5);
}

Triangle::Triangle(point_t pos1, point_t pos2, point_t pos3):
  triangle_{pos1, pos2, pos3}
{
  double side1 = findSide(pos1, pos2);
  double side2 = findSide(pos2, pos3);
  double side3 = findSide(pos3, pos1);
  if (((side3 + side2) <= side1) || ((side2 + side1) <= side3) || ((side3 + side1) <= side2))
  {
    throw std::invalid_argument("wrong triangle");
  }
}

double Triangle::getArea() const
{
  double firstpart = (triangle_[1].x - triangle_[0].x) * (triangle_[2].y - triangle_[0].y);
  double secondpart = (triangle_[2].x - triangle_[0].x) * (triangle_[1].y - triangle_[0].y);
  return std::abs(0.5 * (firstpart - secondpart));
}

rectangle_t Triangle::getFrameRect() const
{
  double maxx = 0.0;
  double maxy = 0.0;
  double minx = 0.0;
  double miny = 0.0;
  for (size_t i = 0; i < 2; i++)
  {
    maxx = std::max(maxx, std::max(triangle_[i].x, triangle_[i + 1].x));
    maxy = std::max(maxy, std::max(triangle_[i].y, triangle_[i + 1].y));
    minx = std::min(minx, std::min(triangle_[i].x, triangle_[i + 1].x));
    miny = std::min(miny, std::min(triangle_[i].y, triangle_[i + 1].y));
  }
  return makeFrame(point_t{minx, miny}, point_t{maxx, maxy});
}

point_t Triangle::findCenterOfTriangle()
{
  double pos1 = (triangle_[0].x + triangle_[1].x + triangle_[2].x) / 3;
  double pos2 = (triangle_[0].y + triangle_[1].y + triangle_[2].y) / 3;
  return (point_t {pos1, pos2});
}

void Triangle::move(point_t point)
{
  point_t center = findCenterOfTriangle();
  move(point.x - center.x, point.y - center.y);
}

point_t operator+(const point_t & pos1, const point_t & pos2)
{
  point_t pos{pos1.x + pos2.x, pos1.y + pos2.y};
  return pos;
}

void Triangle::move(double dx, double dy)
{
  point_t delta{dx, dy};
  for (size_t i = 0; i < 3; i++)
  {
    triangle_[i] = triangle_[i] + delta;
  }
}

void Triangle::scale(double k) noexcept
{
  point_t center = findCenterOfTriangle();
  for (size_t i = 0; i < 3; i++)
  {
    triangle_[i].x = k * (triangle_[i].x - center.x) + center.x;
    triangle_[i].y = k * (triangle_[i].y - center.y) + center.y;
  }
}

Shape* Triangle::clone() const
{
  return new Triangle(triangle_[0], triangle_[1], triangle_[2]);
}
