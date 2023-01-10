#include "complexquad.h"
#include <iostream>
#include <stdexcept>

Shape* inputComplexquad(std::istream &input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  double x4 = 0.0;
  double y4 = 0.0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  if (!input)
  {
    throw std::logic_error("error");
  }
  return new Complexquad(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3}, point_t{x4, y4});
}

point_t findCenter(point_t pos1, point_t pos2, point_t pos3, point_t pos4)
{
  double cx = 0.0;
  double cy = 0.0;
  double a1 = pos1.y - pos2.y;
  double b1 = pos2.x - pos1.x;
  double c1 = pos1.x * pos2.y - pos2.x * pos1.y;
  double a2 = pos3.y - pos4.y;
  double b2 = pos4.x - pos3.x;
  double c2 = pos3.x * pos4.y - pos4.x * pos3.y;
  double det = a1 * b2 - a2 * b1;
  cx = (b1 * c2 - b2 * c1) / det;
  cy = (a2 * c1 - a1 * c2) / det;
  return (point_t {cx, cy});
}

Complexquad::Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4):
  center(findCenter(pos1, pos2, pos3, pos4)),
  triangle_1(new Triangle{pos1, pos4, center}),
  triangle_2(nullptr),
  triangle_3{pos1, pos4, center},
  triangle_4{pos2, pos3, center}
{
  try
  {
    triangle_2 = new Triangle{pos2, pos3, center};
  }
  catch (...)
  {
    delete triangle_1;
    throw;
  }
}

double Complexquad::getArea() const
{
  return triangle_1->getArea() + triangle_2->getArea();
}

rectangle_t Complexquad::getFrameRect() const
{
  double maxx1 = std::max(triangle_4[1].x, std::max(triangle_4[2].x, triangle_3[2].x));
  double minx1 = std::min(triangle_4[1].x, std::min(triangle_4[2].x, triangle_3[2].x));
  double maxy1 = std::max(triangle_4[1].y, std::max(triangle_4[2].y, triangle_3[2].y));
  double miny1 = std::min(triangle_4[1].y, std::min(triangle_4[2].y, triangle_3[2].y));
  double maxx = std::max(triangle_3[1].x, maxx1);
  double minx = std::min(triangle_3[1].x, minx1);
  double maxy = std::max(triangle_3[1].y, maxy1);
  double miny = std::min(triangle_3[1].y, miny1);
  return makeFrame(point_t {minx, miny}, point_t {maxx, maxy});
}

void Complexquad::move(point_t point)
{
  return move(point.x - center.x, point.y - center.y);
}

void Complexquad::move(double dx, double dy)
{
  triangle_1->move(dx, dy);
  triangle_2->move(dx, dy);
}

void Complexquad::scale(double k) noexcept
{
  triangle_1->scale(k);
  triangle_2->scale(k);
}

Shape* Complexquad::clone() const
{
  return new Complexquad(triangle_3[1], triangle_4[1], triangle_4[2], triangle_3[2]);
}

Complexquad::~Complexquad()
{
  delete triangle_1;
  delete triangle_2;
}
