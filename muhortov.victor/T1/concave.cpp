#include "concave.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

Concave::Concave(point_t one, point_t two, point_t three, point_t four):
  first({one.x, one.y}),
  second({two.x, two.y}),
  third({three.x, three.y}),
  fourth({four.x, four.y})
{
  if (checkingConcave(first, second, third, fourth))
  {
    throw std::invalid_argument("Error: invalid concave parameters");
  }
}


std::array< double, 6 > Concave::splitIntoTriangles() const
{
  double a1_ = calculatePointsDistance(first, third);
  double b1_ = calculatePointsDistance(third, second);
  double c1_ = calculatePointsDistance(first, second);
  double a2_ = calculatePointsDistance(third, fourth);
  double b2_ = b1_;
  double c2_ = calculatePointsDistance(fourth, second);
  std::array< double, 6 > arr = {a1_, b1_, c1_, a2_, b2_, c2_};
  return arr;
}

double Concave::getArea() const
{
  std::array< double, 6 > sides = splitIntoTriangles();
  double a1 = sides[0];
  double b1 = sides[1];
  double c1 = sides[2];
  double a2 = sides[3];
  double b2 = sides[4];
  double c2 = sides[5];
  double p1 = (a1 + b1 + c1) / 2;
  double p2 = (a2 + b2 + c2) / 2;
  double s = std::sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c1));
  double s1 = std::sqrt(p2 * (p2 - a2) * (p2 - b2) * (p2 - c2));
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
  double delta_x = position.x - getFrameRect().pos.x;
  double delta_y = position.y - getFrameRect().pos.y;
  move(delta_x, delta_y);
}

void Concave::move(double delta_x, double delta_y)
{
  first = moveToPosition(first, delta_x, delta_y);
  second = moveToPosition(second, delta_x, delta_y);
  third = moveToPosition(third, delta_x, delta_y);
  fourth = moveToPosition(fourth, delta_x, delta_y);
}

void Concave::scaleWithoutCheck(double k)
{
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  first = multiplyPosition(first, center, k);
  second = multiplyPosition(second, center, k);
  third = multiplyPosition(third, center, k);
  fourth = multiplyPosition(fourth, center, k);
}

Shape *Concave::clone() const
{
  return new Concave(first, second, third, fourth);
}
