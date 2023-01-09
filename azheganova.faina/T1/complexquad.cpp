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
  triangle1(new Triangle(pos1, pos4, center)),
  triangle2(new Triangle(pos2, pos3, center)),
  p1(pos1),
  p2(pos2),
  p3(pos3),
  p4(pos4)
{
  double s1 = pos1.x == pos2.x;
  double s2 = pos1.y == pos2.y;
  double s3 = pos1.x == pos3.x;
  double s4 = pos1.y == pos3.y;
  double s5 = pos1.x == pos4.x;
  double s6 = pos1.y == pos4.y;
  double s7 = pos2.x == pos3.x;
  double s8 = pos2.y == pos3.y;
  double s9 = pos2.x == pos4.x;
  double s10 = pos2.y== pos4.y;
  double s11 = pos3.x == pos4.x;
  double s12 = pos3.y == pos4.y;
  double s13 = (pos1.x - pos3.x) * (pos2.y - pos3.y) - (pos2.x - pos3.x) * (pos1.y - pos3.y);
  double s14 = (pos2.x - pos4.x) * (pos3.y - pos4.y) - (pos3.x - pos4.x) * (pos2.y - pos4.y);
  double s15 = (pos1.x - pos4.x) * (pos2.y - pos4.y) - (pos2.x - pos4.x) * (pos1.y - pos4.y);
  double s16 = (pos1.x - pos4.x) * (pos3.y - pos4.y) - (pos3.x - pos4.x) * (pos1.y - pos4.y);
  if ((s1 && s2) || (s3 && s4) || (s5 && s6) || (s7 && s8) || (s9 && s10) || (s11 && s12) || s13 == 0 || s14 == 0|| s15 == 0 || s16 == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
}

double Complexquad::getArea() const
{
  return triangle1->getArea() + triangle2->getArea();
}

rectangle_t Complexquad::getFrameRect() const
{
  double maxx1 = std::max(p2.x, std::max(p3.x, p4.x));
  double minx1 = std::min(p2.x, std::max(p3.x, p4.x));
  double maxy1 = std::max(p2.y, std::max(p3.y, p4.y));
  double miny1 = std::min(p2.y, std::max(p3.y, p4.y));
  double maxx = std::max(p1.x, maxx1);
  double minx = std::min(p1.x, minx1);
  double maxy = std::max(p1.y, maxy1);
  double miny = std::min(p1.y, miny1);
  return makeFrame(point_t{minx, miny}, point_t{maxx, maxy});
}

void Complexquad::move(point_t point)
{
  return move(point.x - center.x, point.y - center.y);
}

void Complexquad::move(double dx, double dy)
{
  triangle1->move(dx, dy);
  triangle2->move(dx, dy);
}

void Complexquad::scale(double k) noexcept
{
  triangle1->scale(k);
  triangle2->scale(k);
}

Shape* Complexquad::clone() const
{
  return new Complexquad(p1, p2, p3, p4);
}

Complexquad::~Complexquad()
{
  delete[] triangle1;
  delete[] triangle2;
}
