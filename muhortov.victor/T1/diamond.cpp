#include "diamond.hpp"
#include <stdexcept>
#include "rectangle.hpp"

Diamond::Diamond(point_t one, point_t two, point_t three):
  positions({findLastDiamondPosition(one, two, three)}),
  rectangle(new Rectangle({positions[2].x, positions[3].y}, {positions[4].x, positions[1].y})),
  rect{rectangle->getFrameRect()}
{}

double Diamond::getArea() const
{
  return 0.5 * rectangle->getArea();
}

rectangle_t Diamond::getFrameRect() const
{
  return rect;
}

void Diamond::move(point_t position)
{
  point_t delta = calculateVectorDifference(position, rect.pos.x, rect.pos.y);
  move(delta.x, delta.y);
}

void Diamond::move(double delta_x, double delta_y)
{
  rect.pos = calculateVectorSum(rect.pos, delta_x, delta_y);
}

void Diamond::scaleWithoutCheck(double k)
{
  rectangle->scaleWithoutCheck(k);
  rect.width *= k;
  rect.height *= k;
}

Shape *Diamond::clone() const
{
  return new Diamond(positions[1], positions[2], positions[3]);
}

Diamond::~Diamond() noexcept
{
  delete rectangle;
}
