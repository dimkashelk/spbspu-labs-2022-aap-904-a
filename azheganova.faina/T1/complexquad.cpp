#include "complexquad.h"
#include <iostream>
#include <stdexcept>

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
  triangle1{pos1, pos4, findCenter(pos1, pos2, pos3, pos4)},
  triangle2{pos2, pos4, findCenter(pos1, pos2, pos3, pos4)}
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
  double firsttriangle1 = 0.0;
  double firsttriangle2 = 0.0;
  double secondtriangle1 = 0.0;
  double secondtriangle2 = 0.0;
  firsttriangle1 = (triangle1[0].x - triangle1[2].x) * (triangle1[1].y - triangle1[2].y);
  firsttriangle2 = (triangle1[1].x - triangle1[2].x) * (triangle1[0].y - triangle1[2].y);
  secondtriangle1 = (triangle2[0].x - triangle2[2].x) * (triangle2[1].y - triangle2[2].y);
  secondtriangle2 = (triangle2[1].x - triangle2[2].x) * (triangle2[0].y - triangle2[2].y);
  return ((0.5 * std::abs((firsttriangle1 - firsttriangle2))) + ((0.5 * std::abs(secondtriangle1 - secondtriangle2))));
}

rectangle_t Complexquad::getFrameRect() const
{
  double maxx1 = std::max(triangle2[1].x, triangle1[1].x);
  double maxy1 = std::max(triangle2[1].y, triangle1[1].y);
  double minx1 = std::min(triangle2[1].x, triangle1[1].x);
  double miny1 = std::min(triangle2[1].y, triangle1[1].y);
  double maxx = std::max(triangle1[0].x, std::max(triangle2[0].x, maxx1));
  double maxy = std::max(triangle1[0].y, std::max(triangle2[0].y, maxy1));
  double minx = std::min(triangle1[0].x, std::min(triangle2[0].x, minx1));
  double miny = std::min(triangle1[0].y, std::min(triangle2[0].y, miny1));
  return makeFrame(point_t {minx, miny}, point_t {maxx, maxy});
}

void Complexquad::move(point_t point)
{
  point_t center = triangle1[2] = triangle2[2];
  return move(point.x - center.x, point.y - center.y);
}

void Complexquad::move(double dx, double dy)
{
  triangle1[0].x += dx;
  triangle1[0].y += dy;
  triangle2[0].x += dx;
  triangle2[0].y += dy;
  triangle2[1].x += dx;
  triangle2[1].y += dy;
  triangle1[1].x += dx;
  triangle1[1].y += dy;
  triangle1[2].x += dx;
  triangle1[2].y += dy;
  triangle2[2].x += dx;
  triangle2[2].y += dy;
}

void Complexquad::scale(double k) noexcept
{
  if (k <= 0)
  {
    std::cerr << "error";
  }
  else
  {
    point_t center = triangle1[2] = triangle2[2];
    triangle1[0].x = k * (triangle1[0].x - center.x) + center.x;
    triangle1[0].y = k * (triangle1[0].y - center.y) + center.y;
    triangle1[1].x = k * (triangle1[1].x - center.x) + center.x;
    triangle1[1].y = k * (triangle1[1].y - center.y) + center.y;
    triangle2[0].x = k * (triangle2[0].x - center.x) + center.x;
    triangle2[0].y = k * (triangle2[0].y - center.y) + center.y;
    triangle2[1].x = k * (triangle2[1].x - center.x) + center.x;
    triangle2[1].y = k * (triangle2[1].y - center.y) + center.y;
  }
}

Shape* Complexquad::clone() const
{
  return new Complexquad(triangle1[0], triangle2[0], triangle2[1], triangle1[1]);
}
