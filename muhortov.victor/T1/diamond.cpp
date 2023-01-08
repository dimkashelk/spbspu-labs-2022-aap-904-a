#include "diamond.hpp"
#include <stdexcept>
#include <cmath>

Diamond::Diamond(point_t one, point_t two, point_t three):
  positions({findLastDiamodPosition(one, two, three)}),
  d1(std::abs(calculatePointsDistance(positions[0], positions[1]))),
  d2(std::abs(calculatePointsDistance(positions[2], positions[3])))
  {}

double Diamond::getArea() const
{
  return 0.5 * d1 * d2;
}

rectangle_t Diamond::getFrameRect() const
{
  if (positions[0].x == positions[1].y)
  {
    return {findDiamondCenter(positions[0], positions[1]), d1, d2};
  }
  else
  {
    return {findDiamondCenter(positions[0], positions[1]), d2, d1};
  }
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
    position = moveToDelta(position, delta_x, delta_y);
  }
}

void Diamond::scaleWithoutCheck(double k)
{
  point_t center = getFrameRect().pos;
  for (point_t &position: positions)
  {
    position = calculateScale(position, center, k);
  }
}

Shape *Diamond::clone() const
{
  return new Diamond(positions[0], positions[1] , positions[2]);
}
