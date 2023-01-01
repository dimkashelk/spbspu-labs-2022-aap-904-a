#ifndef SPBSPU_LABS_2022_AAP_904_A_VECTOR_T_H
#define SPBSPU_LABS_2022_AAP_904_A_VECTOR_T_H
#include "base_types.h"
namespace dimkashelk
{
  struct vector_t
  {
    double x;
    double y;
    vector_t(double x, double y);
    vector_t(point_t end, point_t start);
    vector_t& operator*=(double k);
    double getLength() const;
  };
}
#endif
