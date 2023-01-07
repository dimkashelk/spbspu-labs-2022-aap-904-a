#include "concave.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

Concave::Concave(point_t one, point_t two, point_t three, point_t four):
  rectangle({{four.x, four.y}, std::max(std::max(one.x, two.x), three.x), std::max(std::max(one.y, two.y), three.y)}),
  a(sqrt((three.x - one.x) * (three.x - one.x)  + (three.y - one.y) * (three.y - one.y))),
  b(sqrt((two.x - one.x) * (two.x - one.x)  + (two.y - one.y) * (two.y - one.y))),
  c(sqrt((three.x - two.x) * (three.x - two.x)  + (three.y - two.y) * (three.y - two.y))),
  inTrOne(sqrt((four.x - one.x) * (four.x - one.x)  + (four.y - one.y) * (four.y - one.y))),
  inTrTwo(sqrt((four.x - three.x) * (four.x - three.x)  + (four.y - three.y) * (four.y - three.y))),
  p((a + b + c) / 2),
  pIn((a + inTrOne + inTrTwo) / 2),
  checkTrOne(((one.x - four.x) * (two.y - one.y) - (two.x - one.x) * (one.y - four.y)) > 0),
  checkTrTwo(((two.x - four.x) * (three.y - two.y) - (three.x - two.x) * (two.y - four.y)) > 0),
  checkTrThree(((three.x - four.x) * (one.y - three.y) - (one.x - three.x) * (three.y - four.y)) > 0),
  first({one.x, one.y}),
  second({two.x, two.y}),
  third({three.x, three.y}),
  fourth({four.x, four.y})

{
  if ( a + b < c || a + c < b || b + c < a || one.x == four.x || one.y == four.y || !((checkTrOne && checkTrTwo && checkTrThree)
  || (!checkTrOne && !checkTrTwo && !checkTrThree)))
  {
    throw std::invalid_argument("Error: invalid concave parameters");
  }
}

double Concave::getArea() const
{
  return sqrt(p * (p - a) * (p - b) * (p - c)) - sqrt(pIn * (pIn - a) * (pIn - inTrOne) * (pIn - inTrTwo));
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
  rectangle.pos = {position.x - getFrameRect().pos.x, position.y - getFrameRect().pos.y};
}

void Concave::move(double delta_x, double delta_y)
{
  first.x += delta_x;
  first.y += delta_y;
  second.x += delta_x;
  second.y += delta_y;
  third.x += delta_x;
  third.y += delta_y;
  fourth.x += delta_x;
  fourth.y += delta_y;
}

void Concave::scaleWithoutCheck(double k)
{
  point_t newcenter{getFrameRect().pos.x, getFrameRect().pos.y};
  first.x = k * (first.x - newcenter.x) + newcenter.x;
  first.y = k * (first.y - newcenter.y) + newcenter.y;
  second.x = k * (second.x - newcenter.x) + newcenter.x;
  second.y = k * (second.y - newcenter.y) + newcenter.y;
  third.x = k * (third.x - newcenter.x) + newcenter.x;
  third.y = k * (third.y - newcenter.y) + newcenter.y;
  fourth.x = k * (fourth.x - newcenter.x) + newcenter.x;
  fourth.y = k * (fourth.y - newcenter.y) + newcenter.y;

}

Shape *Concave::clone() const
{
  return new Concave(first, second, third, fourth);
}
