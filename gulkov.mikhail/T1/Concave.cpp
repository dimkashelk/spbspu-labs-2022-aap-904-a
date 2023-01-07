#include "Concave.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

Concave::Concave(point_t one, point_t two, point_t three, point_t four):
  first({one.x, one.y}),
  second({two.x, two.y}),
  third({three.x, three.y}),
  fourth({four.x, four.y})
{
  if (validateConcave(one, two, three, four))
  {
    throw std::invalid_argument("Bad input, invalid concave size");
  }
}


std::array< double, 6 > Concave::splitIntoTriangles() const
{
  double a_ = calcVectorLength(first, third);
  double b_ = calcVectorLength(third, second);
  double c_ = calcVectorLength(first, second);
  double a1_ = calcVectorLength(third, fourth);
  double b1_ = b_;
  double c1_ = calcVectorLength(fourth, second);
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
  double up = std::max({first.y, second.y, third.y});
  double down = std::min({first.y, second.y, third.y});
  double left = std::min({first.x, second.x, third.x});
  double right = std::max({first.x, second.x, third.x});
  return {{(right + left) / 2, (up + down) / 2}, right - left, up - down};
}

void Concave::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}

void Concave::move(double dx, double dy)
{
  first.x += dx;
  first.y += dy;
  second.x += dx;
  second.y += dy;
  third.x += dx;
  third.y += dy;
  fourth.x += dx;
  fourth.y += dy;
}

void Concave::makeScale(double k)
{
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  first.x = k * (first.x - center.x) + center.x;
  first.y = k * (first.y - center.y) + center.y;
  second.x = k * (second.x - center.x) + center.x;
  second.y = k * (second.y - center.y) + center.y;
  third.x = k * (third.x - center.x) + center.x;
  third.y = k * (third.y - center.y) + center.y;
  fourth.x = k * (fourth.x - center.x) + center.x;
  fourth.y = k * (fourth.y - center.y) + center.y;
}

Shape *Concave::clone() const
{
  return new Concave(first, second, third, fourth);
}
