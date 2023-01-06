#include "complexquad.h"
#include <iostream>
#include <stdexcept>

Complexquad::Complexquad():
  complexquad1{point_t{0.0, 0.0}, point_t{0.0, 0.0}, point_t{0.0, 0.0}, point_t{0.0, 0.0}}
{}

Complexquad::Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4):
  complexquad1{pos1, pos2, pos3, pos4}
{
  if (((pos1.x == pos2.x) && (pos1.y== pos2.y)) || ((pos1.x == pos3.x) && (pos1.y== pos3.y)) || ((pos1.x == pos4.x) && (pos1.y== pos4.y)))
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (((pos2.x == pos3.x) && (pos2.y== pos3.y)) || ((pos2.x == pos4.x) && (pos2.y== pos4.y)) || ((pos3.x == pos4.x) && (pos3.y== pos4.y)))
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (( pos1.x - pos3.x ) * ( pos2.y - pos3.y ) - ( pos2.x - pos3.x ) * ( pos1.y - pos3.y ) == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (( pos2.x - pos4.x ) * ( pos3.y - pos4.y ) - ( pos3.x - pos4.x ) * ( pos2.y - pos4.y ) == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (( pos1.x - pos4.x ) * ( pos2.y - pos4.y ) - ( pos2.x - pos4.x ) * ( pos1.y - pos4.y ) == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
  if (( pos1.x - pos4.x ) * ( pos3.y - pos4.y ) - ( pos3.x - pos4.x ) * ( pos1.y - pos4.y ) == 0)
  {
    throw std::invalid_argument("wrong complexquad");
  }
}

double Complexquad::getArea() const
{
  double x = 0.0;
  double equationx = 0.0;
  double equationy = 0.0;
  double k1 = (complexquad1[0].y - complexquad1[1].y) / (complexquad1[0].x - complexquad1[1].x);
  double b1 = complexquad1[1].y - k1 * complexquad1[1].x;
  double k2 = (complexquad1[2].y - complexquad1[3].y) / (complexquad1[2].x - complexquad1[3].x);
  double b2 = complexquad1[3].y - k1 * complexquad1[3].x;
  for (x = 0; x < 1000; x++)
  {
    if (k1 * x + b1 == k2 * x + b2)
    {
      equationx = x;
      equationy = k1 * equationx + b1;
    }
  }
  point_t center = {equationx, equationy};
  double firsttriangle1 = 0.0;
  double firsttriangle2 = 0.0;
  double secondtriangle1 = 0.0;
  double secondtriangle2 = 0.0;
  double areaforcomplexquad = 0.0;
  firsttriangle1 = (complexquad1[0].x - complexquad1[3].x) * (center.y - complexquad1[3].y);
  firsttriangle2 = (center.x - complexquad1[3].x) * (complexquad1[0].y - complexquad1[3].y);
  secondtriangle1 = (complexquad1[2].x - complexquad1[1].x) * (center.y - complexquad1[1].y);
  secondtriangle2 = (center.x - complexquad1[1].x) * (complexquad1[2].y - complexquad1[1].y);
  areaforcomplexquad = (0.5 * (secondtriangle1 - secondtriangle2)) + (0.5 * (firsttriangle1 - firsttriangle2));
  return std::abs(areaforcomplexquad);
}

rectangle_t Complexquad::getFrameRect() const
{
  double x = 0.0;
  double equationx = 0.0;
  double equationy = 0.0;
  double k1 = (complexquad1[0].y - complexquad1[1].y) / (complexquad1[0].x - complexquad1[1].x);
  double b1 = complexquad1[1].y - k1 * complexquad1[1].x;
  double k2 = (complexquad1[2].y - complexquad1[3].y) / (complexquad1[2].x - complexquad1[3].x);
  double b2 = complexquad1[3].y - k1 * complexquad1[3].x;
  for (x = 0; x < 1000; x++)
  {
    if (k1 * x + b1 == k2 * x + b2)
    {
      equationx = x;
      equationy = k1 * equationx + b1;
    }
  }
  point_t center = {equationx, equationy};
  double maxx1 = std::max(complexquad1[2].x, complexquad1[3].x);
  double maxy1 = std::max(complexquad1[2].y, complexquad1[3].y);
  double minx1 = std::min(complexquad1[2].x, complexquad1[3].x);
  double miny1 = std::min(complexquad1[2].y, complexquad1[3].y);
  double maxx = std::max(complexquad1[0].x, std::max(complexquad1[1].x, maxx1));
  double maxy = std::max(complexquad1[0].y, std::max(complexquad1[1].y, maxy1));
  double minx = std::min(complexquad1[0].x, std::min(complexquad1[1].x, minx1));
  double miny = std::min(complexquad1[0].y, std::min(complexquad1[1].y, miny1));
  return makeFrame(point_t {(minx + maxx) / 2}, point_t {(maxy + miny) / 2});
}
void Complexquad::move(point_t point)
{
  double x = 0.0;
  double equationx = 0.0;
  double equationy = 0.0;
  double k1 = (complexquad1[0].y - complexquad1[1].y) / (complexquad1[0].x - complexquad1[1].x);
  double b1 = complexquad1[1].y - k1 * complexquad1[1].x;
  double k2 = (complexquad1[2].y - complexquad1[3].y) / (complexquad1[2].x - complexquad1[3].x);
  double b2 = complexquad1[3].y - k1 * complexquad1[3].x;
  for (x = 0; x < 1000; x++)
  {
    if (k1 * x + b1 == k2 * x + b2)
    {
      equationx = x;
      equationy = k1 * equationx + b1;
    }
  }
  point_t center = {equationx, equationy};
  return move(point.x - center.x, point.y - center.y);
}
void Complexquad::move(double dx, double dy)
{
  complexquad1[0].x += dx;
  complexquad1[0].y += dy;
  complexquad1[1].x += dx;
  complexquad1[1].y += dy;
  complexquad1[2].x += dx;
  complexquad1[2].y += dy;
  complexquad1[3].x += dx;
  complexquad1[3].y += dy;
}
void Complexquad::scale(double k) noexcept
{
  double x = 0.0;
  double equationx = 0.0;
  double equationy = 0.0;
  double k1 = (complexquad1[0].y - complexquad1[1].y) / (complexquad1[0].x - complexquad1[1].x);
  double b1 = complexquad1[1].y - k1 * complexquad1[1].x;
  double k2 = (complexquad1[2].y - complexquad1[3].y) / (complexquad1[2].x - complexquad1[3].x);
  double b2 = complexquad1[3].y - k1 * complexquad1[3].x;
  for (x = 0; x < 1000; x++)
  {
    if (k1 * x + b1 == k2 * x + b2)
    {
      equationx = x;
      equationy = k1 * equationx + b1;
    }
  }
  point_t center = {equationx, equationy};
  complexquad1[0].x = k * (complexquad1[0].x - center.x) + center.x;
  complexquad1[1].x = k * (complexquad1[1].x - center.x) + center.x;
  complexquad1[2].x = k * (complexquad1[2].x - center.x) + center.x;
  complexquad1[3].x = k * (complexquad1[3].x - center.x) + center.x;
  complexquad1[0].y = k * (complexquad1[0].y - center.y) + center.y;
  complexquad1[1].y = k * (complexquad1[1].y - center.y) + center.y;
  complexquad1[2].y = k * (complexquad1[2].y - center.y) + center.y;
  complexquad1[3].y = k * (complexquad1[3].y - center.y) + center.y;
}

Shape* Complexquad::clone() const
{
  Complexquad *copy = new Complexquad(complexquad1[0], complexquad1[1], complexquad1[2], complexquad1[3]);
  return copy;
}
