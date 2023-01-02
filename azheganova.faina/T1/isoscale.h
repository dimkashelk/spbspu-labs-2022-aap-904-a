#ifndef ISOSCALE_H
#define ISOSCALE_H
#include "shape.h"
#include "compositeshape.h"

void isoScale(shape * s, const point_t & pos, double k);
void isotropicScaling(CompositeShape &compositeShape, point_t point, double k);
#endif
