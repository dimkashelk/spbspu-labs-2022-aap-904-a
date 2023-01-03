#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_FUNCTIONS_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_FUNCTIONS_H
#include "base_types.h"
namespace dimkashelk
{
  point_t getLeftDownPoint(rectangle_t rect);
  point_t getRightUpPoint(rectangle_t rect);
  bool isRectangularTriangle(point_t *points);
  point_t getCenterOfWeight(point_t *points, size_t size);
}
#endif
