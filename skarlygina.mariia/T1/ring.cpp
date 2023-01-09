#include "ring.h"
#include <stdexcept>
#include "ellipse.h"
Ring::Ring(point_t center, double radius_small, double radius_big):
  center_(center),
  radius_small_(radius_small),
  radius_big_(radius_big),
  smallEllipse(new Ellipse(center, radius_small, radius_small)),
  bigEllipse(new Ellipse(center, radius_big, radius_big))
{
  if (isBadRing())
  {
	throw std::invalid_argument("Error: false ring parameters");
  }
}

bool Ring::isBadRing()
{
  return (radius_big_ <= radius_small_ || radius_big_ <= 0 || radius_small_ <= 0);
}

double Ring::getArea() const
{
  const double pi = 3.1416;
  return (bigEllipse->getArea() - smallEllipse->getArea());
}

rectangle_t Ring::getFrameRectangle() const
{
  return bigEllipse->getFrameRectangle();
}

void Ring::move(double dx, double dy)
{
  //center_ = baseFunctions::findSummVector(center_, dx, dy);
  bigEllipse->move(dx, dy);
}

void Ring::move(point_t position)
{
  //point_t diff = baseFunctions::findDifference(position, getFrameRectangle().position);
  //move(diff.x, diff.y);
  bigEllipse->move(position);
}

void Ring::scale(double k)
{
  //baseFunctions::findCorrectKoeff(k);
  //point_t center = getFrameRectangle().position;
  //radius_small_ = baseFunctions::findRadius(radius_small_, k);
  //radius_big_ = baseFunctions::findRadius(radius_big_, k);
  //center_ = baseFunctions::makeCenterMove(center_, center, k);
	bigEllipse->scale(k);
	smallEllipse->scale(k);
}
