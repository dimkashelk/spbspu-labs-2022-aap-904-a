#include "Concave.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

Concave::Concave(point_t one, point_t two, point_t three, point_t four):
  one_(one),
  two_(two),
  three_(three),
  four_(four),
  rect_({{four.x, four.y}, std::max(std::max(one.x, two.x), three.x), std::max(std::max(one.y, two.y), three.y)})
{
  double a = sqrt((three.x - one.x) * (three.x - one.x) + (three.y - one.y) * (three.y - one.y));
  double b = sqrt((two.x - one.x) * (two.x - one.x) + (two.y - one.y) * (two.y - one.y));
  double c = sqrt((three.x - two.x) * (three.x - two.x) + (three.y - two.y) * (three.y - two.y));

  bool triangle1 = ((one.x - four.x) * (two.y - one.y) - (two.x - one.x) * (one.y - four.y)) > 0;
  bool triangle2 = ((two.x - four.x) * (three.y - two.y) - (three.x - two.x) * (two.y - four.y)) > 0;
  bool triangle3 = ((three.x - four.x) * (one.y - three.y) - (one.x - three.x) * (three.y - four.y)) > 0;

  bool fail_vec = a + b < c || a + c < b || b + c < a;
  bool fail_coord = one.x == four.x || one.y == four.y;
  bool check_triangles = !((triangle1 && triangle2 && triangle3) || (!triangle1 && !triangle2 && !triangle3));

  if (fail_vec || fail_coord)
  {
    throw std::invalid_argument("Bad input, invalid concave size");
  }

//  double a = std::sqrt(pow((one.x - two.x), 2) + pow((one.y - two.y), 2));
//  double b = std::sqrt(pow((three.x - two.x), 2) + pow((three.y - two.y), 2));
//  double c = std::sqrt(pow((one.x - three.x), 2) + pow((one.y - three.y), 2));
//  if (a >= b + c || b >= a + c || c >= b + a)
//  {
//    throw std::invalid_argument("Bad input, invalid triangle size");
//  }
//  a = (one.x - four.x) * (two.y - one.y) - (two.x - one.x) * (one.y - four.y);
//  b = (two.x - four.x) * (three.y - two.y) - (three.x - two.x) * (two.y - four.y);
//  c = (three.x - four.x) * (one.y - three.y) - (one.x - three.x) * (three.y - four.y);
//  if ((a > 0 && b > 0 && c > 0 || a < 0 && b < 0 && c < 0))
//  {
//    throw std::invalid_argument("Bad input, invalid concave size");
//  }
}

double Concave::getArea() const
{
  double det1 = std::abs(one_.x * two_.y - one_.y * two_.x);
  double det2 = std::abs(two_.x * three_.y - two_.y * three_.x);
  double det3 = std::abs(three_.x * four_.y - three_.y * four_.x);
  double det4 = std::abs(four_.x * one_.y - four_.y * one_.x);
  return 0.5 * (det1 + det2 + det3 + det4);
}

rectangle_t Concave::getFrameRect() const
{
  return rect_;
}

void Concave::move(point_t position)
{
  rect_.pos = position;
}

void Concave::move(double dx, double dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Concave::makeScale(double value)
{
}