#include "diamond.hpp"
#include <stdexcept>
#include <cmath>

Diamond::Diamond(point_t one, point_t two, point_t three):
  positions({findLastDiamondPosition(one, two, three)}),
  d1(std::abs(calculatePointsDistance(positions[1], positions[3]))),
  d2(std::abs(calculatePointsDistance(positions[2], positions[4])))
  {}

double Diamond::getArea() const
{
  return 0.5 * d1 * d2;
}

rectangle_t Diamond::getFrameRect() const
{
  return {positions[0], d2, d1};
}

void Diamond::move(point_t position)
{
  point_t delta = calculateVectorDifference(position, getFrameRect().pos.x, getFrameRect().pos.y);
  move(delta.x, delta.y);
}

void Diamond::move(double delta_x, double delta_y)
{
  for (point_t &position: positions)
  {
    position = calculateVectorSum(position, delta_x, delta_y);
  }
}

void Diamond::scaleWithoutCheck(double k)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 1; i < 5; i++)
  {
    positions[i] = calculateScale(positions[i], center, k);
  }
  d1 *= k;
  d2 *= k;
}

Shape *Diamond::clone() const
{
  return new Diamond(positions[1], positions[2] , positions[3]);
}
