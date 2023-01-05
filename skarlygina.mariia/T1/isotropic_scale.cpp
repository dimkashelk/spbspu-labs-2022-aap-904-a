#include "isotropic_scale.h"
void makeIsotropicScaling(Shape* figure, point_t point, double k)
{
  double firstPosX = figure->getFrameRectangle().position.x;
  double firstPosY = figure->getFrameRectangle().position.y;
  double dx = point.x - firstPosX;
  double dy = point.y - firstPosY;
  figure->move(dx, dy);
  dx *= -k;
  dy *= -k;
  figure->scale(k);
  figure->move(dx, dy);
}
