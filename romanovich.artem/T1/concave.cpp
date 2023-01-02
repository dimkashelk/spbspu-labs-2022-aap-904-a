#include "concave.h"
#include <cmath>
Concave::Concave(point_t *pointsArray) :
  A(pointsArray[0]),
  B(pointsArray[1]),
  C(pointsArray[2]),
  D(pointsArray[3])
{
}
double Concave::getArea() const
{
  double ax = C.x - B.x;
  double ay = C.y - B.y;
  double by = A.y - B.y;
  double bx = A.x - B.x;
  double cx = C.x - D.x;
  double cy = C.y - D.y;
  double dx = D.x - B.x;
  double dy = D.y - B.y;
  double fx = A.x - C.x;
  double fy = A.y - C.y;
  double a = sqrt(ax * ax + ay * ay);
  double b = sqrt(bx * bx + by * by);
  double c = sqrt(cx * cx + cy * cy);
  double d = sqrt(dx * dx + dy * dy);
  double f = sqrt(fx * fx + fy * fy);
  double p1 = (a + b + f) / 2;
  double p2 = (a + d + c) / 2;
  double s1 = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - c));
  double s2 = sqrt(p2 * (p2 - d) * (p2 - b) * (p2 - c));
  return s1 - s2;
}
rectangle_t Concave::getFrameRect() const
{
  rectangle_t frameRect{};
  frameRect.height = A.y - C.y;
  frameRect.width = A.x - C.x;
  frameRect.pos.x = (C.x + C.x) / 2;
  frameRect.pos.y = (A.y + C.y) / 2;
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
Concave::Concave() = default;
