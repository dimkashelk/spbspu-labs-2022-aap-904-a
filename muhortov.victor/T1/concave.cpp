#include "concave.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

Concave::Concave(point_t one, point_t two, point_t three, point_t four):
  positions{one, two, three, four}
{
  if (checkingConcave(positions[0], positions[1], positions[2], positions[3]))
  {
    throw std::invalid_argument("Error: invalid concave parameters");
  }
}


std::array< double, 6 > Concave::splitIntoTriangles() const
{
  double a1_ = calculatePointsDistance(positions[0], positions[2]);
  double b1_ = calculatePointsDistance(positions[2], positions[1]);
  double c1_ = calculatePointsDistance(positions[0], positions[1]);
  double a2_ = calculatePointsDistance(positions[2], positions[3]);
  double b2_ = b1_;
  double c2_ = calculatePointsDistance(positions[3], positions[2]);
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
  double up = std::max({positions[0].y, positions[1].y, positions[2].y});
  double down = std::min({positions[0].y, positions[1].y, positions[2].y});
  double left = std::min({positions[0].x, positions[1].x, positions[2].x});
  double right = std::max({positions[0].x, positions[1].x, positions[2].x});
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
  for (point_t &position: positions)
  {
    position = moveToPosition(position, delta_x, delta_y);
  }
}

void Concave::scaleWithoutCheck(double k)
{
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  for (point_t &position: positions)
  {
    position = multiplyPosition(position, center, k);
  }
}

Shape *Concave::clone() const
{
  return new Concave(positions[0], positions[1], positions[2], positions[3]);
}
