#ifndef SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#define SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#include <cstddef>
#include "triangle.h"
class Polygon: public Shape
{
public:
  Polygon(point_t *points, size_t size);
private:
  Triangle **triangles;
  size_t count;
};
#endif
