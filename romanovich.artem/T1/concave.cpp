#include "concave.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
Concave::Concave(point_t *pointsArray) :
  A(pointsArray[0]),
  B(pointsArray[1]),
  C(pointsArray[2]),
  D(pointsArray[3])
{
  if (!goodConcaveInput())
  {
    throw std::invalid_argument("Bad concave input.");
  }
}
bool Concave::goodConcaveInput() const
{
  double *sides = getSides();
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  delete[] sides;
  double max_ = std::max({a, b, c});
  double min_ = std::max({a, b, c});
  double midl_ = a + b + c - max_ - min_;
  bool firstThreeTriangle = (max_ < min_ + midl_);
  bool fourthLeftAB = ((D.x - A.x) * (B.y - A.y) - (D.y - A.y) * (B.x - A.x) > 0);
  bool fourthLeftBC = ((D.x - B.x) * (C.y - B.y) - (D.y - B.y) * (C.x - B.x) > 0);
  bool fourthLeftCA = ((D.x - C.x) * (A.y - C.y) - (D.y - C.y) * (A.x - C.x) > 0);
  if (fourthLeftAB && fourthLeftBC && fourthLeftCA)
  {
    return firstThreeTriangle;
  }
  if (!fourthLeftAB && !fourthLeftBC && !fourthLeftCA)
  {
    return firstThreeTriangle;
  }
  return false;
}
double *Concave::getSides() const
{
  double a_x = A.x - C.x;
  double a_y = A.y - C.y;
  double b_x = C.x - B.x;
  double b_y = C.y - B.y;
  double c_y = A.y - B.y;
  double c_x = A.x - B.x;
  double a1_x = C.x - D.x;
  double a1_y = C.y - D.y;
  double b1_x = b_x;
  double b1_y = b_y;
  double c1_x = D.x - B.x;
  double c1_y = D.y - B.y;
  double a = sqrt(a_x * a_x + a_y * a_y);
  double b = sqrt(b_x * b_x + b_y * b_y);
  double c = sqrt(c_x * c_x + c_y * c_y);
  double a1 = sqrt(a1_x * a1_x + a1_y * a1_y);
  double b1 = sqrt(b1_x * b1_x + b1_y * b1_y);
  double c1 = sqrt(c1_x * c1_x + c1_y * c1_y);
  return new double[6]{a, b, c, a1, b1, c1};
}
double Concave::getArea() const
{
  double *sides = getSides();
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double a1 = sides[3];
  double b1 = sides[4];
  double c1 = sides[5];
  delete[] sides;
  double p1 = (a + b + c) / 2;
  double p2 = (a1 + b1 + c1) / 2;
  double s1 = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - c));
  double s2 = sqrt(p2 * (p2 - a1) * (p2 - b1) * (p2 - c1));
  return s1 - s2;
}
rectangle_t Concave::getFrameRect() const
{
  rectangle_t frameRect{};
  double sup = std::max({A.y, B.y, C.y});
  double inf = std::min({A.y, B.y, C.y});
  frameRect.height = sup - inf;
  double left = std::min({A.x, B.x, C.x});
  double right = std::max({A.x, B.x, C.x});
  frameRect.width = right - left;
  frameRect.pos.x = (right + left) / 2;
  frameRect.pos.y = (sup + inf) / 2;
  return frameRect;
}
void Concave::move(double dx, double dy)
{
  A.x += dx;
  B.x += dx;
  C.x += dx;
  D.x += dx;
  A.y += dy;
  B.y += dy;
  C.y += dy;
  D.y += dy;
}
void Concave::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Concave::scale(double k)
{
  if (k > 0)
  {
    double centerX = getFrameRect().pos.x;
    double centerY = getFrameRect().pos.y;
    A.x = k * (A.x - centerX) + centerX;
    A.y = k * (A.y - centerY) + centerY;
    C.x = k * (C.x - centerX) + centerX;
    C.y = k * (C.y - centerY) + centerY;
    B.x = k * (B.x - centerX) + centerX;
    B.y = k * (B.y - centerY) + centerY;
    D.x = k * (D.x - centerX) + centerX;
    D.y = k * (D.y - centerY) + centerY;
  }
  else
  {
    throw std::invalid_argument("Invalid scaling coeff.");
  }
}
Concave *Concave::clone() const
{
  return nullptr;
}
void Concave::isoScale(Concave &concave, double secondPosX, double secondPosY, double k)
{
  double firstPosX = concave.getFrameRect().pos.x;
  double firstPosY = concave.getFrameRect().pos.y;
  double dx = secondPosX - firstPosX;
  double dy = secondPosY - firstPosY;
  concave.move(dx, dy);
  dx *= -k;
  dy *= -k;
  concave.scale(k);
  concave.move(dx, dy);
}
