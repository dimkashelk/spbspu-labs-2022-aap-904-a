#include "ellipse.h"
dimkashelk::Ellipse::Ellipse(point_t point, double height, double width):
  triangles(makeTriangles(point, height, width))
{}
