#ifndef SPBSPU_LABS_2022_AAP_904_A_REGULAR_H
#define SPBSPU_LABS_2022_AAP_904_A_REGULAR_H
#include "shape.h"
#include "triangle.h"
class Regular: public Shape
{
public:
  Regular(double x1, double y1, double x2, double y2, double x3, double y3);
private:
  Triangle triangle;
  size_t count;
};
#endif
