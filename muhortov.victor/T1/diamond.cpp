#include "diamond.hpp"
#include <stdexcept>
#include <cmath>
#include <array>
#include "rectangle.hpp"

Diamond::Diamond(point_t one, point_t two, point_t three):
  //rectangle({positions[2].x, positions[3].y}, {positions[4].x, positions[1].y})
  rectangle({0, 0}, {0, 0})
{
  std::array< point_t, 5 > positions({findLastDiamondPosition(one, two, three)});
  rectangle({positions[2].x, positions[3].y}, {positions[4].x, positions[1].y});
}

double Diamond::getArea() const
{
  return 0.5 * rectangle.getArea();
}

rectangle_t Diamond::getFrameRect() const
{
  return rectangle.getFrameRect();
}

void Diamond::move(point_t position)
{
  point_t delta = calculateVectorDifference(position, rectangle.getFrameRect().pos.x, rectangle.getFrameRect().pos.y);
  move(delta.x, delta.y);
}

void Diamond::move(double delta_x, double delta_y)
{
  rectangle.getFrameRect().pos = calculateVectorSum(rectangle.getFrameRect().pos, delta_x, delta_y);
}

void Diamond::scaleWithoutCheck(double k)
{
  rectangle.scaleWithoutCheck(k);
}

Shape *Diamond::clone() const
{
  return new Diamond(positions[1], positions[2], positions[3]);
}
