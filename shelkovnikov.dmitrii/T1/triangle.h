#ifndef SPBSPU_LABS_2022_AAP_904_A_TRIANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_TRIANGLE_H
#include "shape.h"
class Triangle: public Shape
{
public:
  Triangle(point_t point1, point_t point2, point_t point3);
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
  bool isRectangular();
  point_t* getPoints();
  point_t getCenterOfGravity();
private:
  point_t point1;
  point_t point2;
  point_t point3;
};
#endif
