#ifndef SUPPORTFUNCTIONS_H
#define SUPPORTFUNCTIONS_H
#include "shape.h"
void movePoint(point_t &p, double dx, double dy);
void movePointBecauseOfScale(point_t &p, point_t &zoomCenter, double k);
#endif
