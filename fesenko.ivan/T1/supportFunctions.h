#ifndef SUPPORTFUNCTIONS_H
#define SUPPORTFUNCTIONS_H
#include "shape.h"
void movePoint(point_t &p, double dx, double dy);
void movePointBecauseOfScale(point_t &p, point_t &zoomCenter, double k);
bool isIntersectionOfSegments(point_t &p1, point_t &p2, point_t &p3, point_t &p4);
#endif
