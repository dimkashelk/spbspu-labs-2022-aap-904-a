#include "Concave.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

Concave::Concave(point_t one, point_t two, point_t three, point_t four):
  dots_{one, two, three, four}
{
  if (validateConcave(one, two, three, four))
  {
    throw std::invalid_argument("Bad input, invalid concave size");
  }
}


std::array< double, 6 > Concave::splitIntoTriangles() const
{
  double a_ = calcVectorLength(dots_[0], dots_[2]);
  double b_ = calcVectorLength(dots_[2], dots_[1]);
  double c_ = calcVectorLength(dots_[0], dots_[1]);
  double a1_ = calcVectorLength(dots_[2], dots_[3]);
  double b1_ = b_;
  double c1_ = calcVectorLength(dots_[3], dots_[1]);
  std::array< double, 6 > arr = {a_, b_, c_, a1_, b1_, c1_};
  return arr;
}

double Concave::getArea() const
{
  std::array< double, 6 > sides = splitIntoTriangles();
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double a1 = sides[3];
  double b1 = sides[4];
  double c1 = sides[5];
  double p = (a + b + c) / 2;
  double p1 = (a1 + b1 + c1) / 2;
  double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
  double s1 = std::sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c1));
  return s - s1;
}

rectangle_t Concave::getFrameRect() const
{
  double top = std::max({dots_[0].y, dots_[1].y, dots_[2].y});
  double down = std::min({dots_[0].y, dots_[1].y, dots_[2].y});
  double left = std::min({dots_[0].x, dots_[1].x, dots_[2].x});
  double right = std::max({dots_[0].x, dots_[1].x, dots_[2].x});
  return {{(right + left) / 2, (top + down) / 2}, right - left, top - down};
}

void Concave::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}

void Concave::move(double dx, double dy)
{
  dots_[0].x += dx;
  dots_[0].y += dy;
  dots_[1].x += dx;
  dots_[1].y += dy;
  dots_[2].x += dx;
  dots_[2].y += dy;
  dots_[3].x += dx;
  dots_[3].y += dy;
}

void Concave::makeScale(double k)
{
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  dots_[0].x = k * (dots_[0].x - center.x) + center.x;
  dots_[0].y = k * (dots_[0].y - center.y) + center.y;
  dots_[1].x = k * (dots_[1].x - center.x) + center.x;
  dots_[1].y = k * (dots_[1].y - center.y) + center.y;
  dots_[2].x = k * (dots_[2].x - center.x) + center.x;
  dots_[2].y = k * (dots_[2].y - center.y) + center.y;
  dots_[3].x = k * (dots_[3].x - center.x) + center.x;
  dots_[3].y = k * (dots_[3].y - center.y) + center.y;
}

Shape *Concave::clone() const
{
  return new Concave(dots_[0], dots_[1], dots_[2], dots_[3]);
}
