#ifndef SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#include "shape.h"
class Rectangle: public Shape
{
public:
  Rectangle(point_t point, double width, double height);
  Rectangle(rectangle_t rectangle);
private:
  rectangle_t rectangle;
};
#endif
