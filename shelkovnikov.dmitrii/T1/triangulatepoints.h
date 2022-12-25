#ifndef SPBSPU_LABS_2022_AAP_904_A_TRIANGULATEPOINTS_H
#define SPBSPU_LABS_2022_AAP_904_A_TRIANGULATEPOINTS_H
#include <cstddef>
#include "base_types.h"
#include "vector_t.h"
#include "triangle.h"
class TriangulatePoints
{
public:
  TriangulatePoints(point_t *points, size_t size);
  Triangle operator()() const;
  size_t getSize() const;
private:
  point_t *points_;
  size_t size_;
  Triangle **triangles_;
  double getMixedProduct(vector_t a, vector_t b) const;
  bool containsAnyPoint(const Triangle &triangle) const;
  void removePoint(size_t ind);
  bool containsThreePointsOnLine();
};
#endif
