#include "isotropic_scale.h"
void makeIsotropicScaling(Shape* figure, point_t point, double k)
{
  point_t position{figure->getFrameRectangle().position.x, figure->getFrameRectangle().position.y};
  double dx = point.x - position.x;
  double dy = point.y - position.y;
  figure->move(dx, dy);
  dx = - dx * k;
  dy = - dy * k;
  figure->scale(k);
  figure->move(dx, dy);
}
