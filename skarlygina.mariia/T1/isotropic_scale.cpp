#include "isotropic_scale.h"
void makeIsotropicScaling(Shape* figure, point_t point, double k)
{
  double position_x = figure->getFrameRectangle().position.x;
  double position_y = figure->getFrameRectangle().position.y;
  double dx = point.x - position_x;
  double dy = point.y - position_y;
  figure->move(dx, dy);
  dx *= - k;
  dy *= - k;
  figure->scale(k);
  figure->move(dx, dy);
}
