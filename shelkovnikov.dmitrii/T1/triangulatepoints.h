#ifndef SPBSPU_LABS_2022_AAP_904_A_TRIANGULATEPOINTS_H
#define SPBSPU_LABS_2022_AAP_904_A_TRIANGULATEPOINTS_H
#include <cstddef>
#include "base_types.h"
#include "triangle.h"
namespace dimkashelk
{
  class TriangulatePoints
  {
  public:
    TriangulatePoints(const point_t *points, size_t size);
    ~TriangulatePoints();
    Triangle operator()();
    bool hasNext() const;
  private:
    point_t *points_;
    size_t size_;
    size_t point_;
    double getMixedProduct(point_t p1_end, point_t p1_start, point_t p2_end, point_t p2_start) const;
  };
}
#endif
