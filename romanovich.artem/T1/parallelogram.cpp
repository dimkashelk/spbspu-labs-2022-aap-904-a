#include "parallelogram.h"
Parallelogram::Parallelogram(point_t *pointsArray) :
  A(pointsArray[0]),
  B(pointsArray[1]),
  C(pointsArray[2]),
  D(pointsArray[3])
{
}
double Parallelogram::getArea() const
{
  return -1;
}
rectangle_t Parallelogram::getFrameRect() const
{
  rectangle_t frameRect{};
  return frameRect;
}
void Parallelogram::move(double dx, double dy)
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
void Parallelogram::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Parallelogram::scale(double k)
{
  if (k > 0)
  {
  }
}
Parallelogram *Parallelogram::clone() const
{
  return nullptr;
}
void Parallelogram::isoScale(Parallelogram &parallelogram, double secondPosX, double secondPosY, double k)
{
  double firstPosX = parallelogram.getFrameRect().pos.x;
  double firstPosY = parallelogram.getFrameRect().pos.y;
  double dx = secondPosX - firstPosX;
  double dy = secondPosY - firstPosY;
  parallelogram.move(dx, dy);
  dx *= -k;
  dy *= -k;
  parallelogram.scale(k);
  parallelogram.move(dx, dy);
}
Parallelogram::Parallelogram() = default;
