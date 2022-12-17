#ifndef SPBSPU_LABS_2022_AAP_904_A_TRIANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_TRIANGLE_H
#include "shape.h"
class Triangle: public Shape
{
public:
  Triangle(point_t point1, point_t point2, point_t point3);
private:
  point_t point1;
  point_t point2;
  point_t point3;
};
#endif
