#ifndef SPBSPU_LABS_2022_AAP_904_A_TRIANGULATEPOINTS_H
#define SPBSPU_LABS_2022_AAP_904_A_TRIANGULATEPOINTS_H
#include <cstddef>
#include "base_types.h"
#include "triangle.h"
class TriangulatePoints
{
public:
  TriangulatePoints(point_t *points, size_t size);
  Triangle* operator()() const;
private:
  point_t *points;
  size_t size;
  double get_mixed_product(vector_t a, vector_t b) const;
  bool containsAnyPoint(const Triangle &triangle) const;
};
#endif
