#include "isotropic_scale.h"
#include <stdexcept>
void makeIsotropicScaling(Shape* figure, point_t point, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error: koeff is under zero");
  }
  try
  {
    point_t position{ figure->getFrameRectangle().position.x, figure->getFrameRectangle().position.y };
    double dx = point.x - position.x;
    double dy = point.y - position.y;
    figure->move(dx, dy);
    dx = -dx * k;
    dy = -dy * k;
    figure->scale(k);
    figure->move(dx, dy);
  }
  catch (const std::invalid_argument& e)
  {
    throw std::invalid_argument("Error");
  }
}
