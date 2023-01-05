#include "inputtriangle.h"
#include <iostream>
#include "compositeshape.h"

Shape* inputTriangle(std::istream &input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  point_t point[3];
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  point[0] = point_t {x1, y1};
  point[1] = point_t {x2, y2};
  point[2] = point_t {x3, y3};
  if (!input)
  {
    std::cout << "error";
  }
  return new Triangle(point[0], point[1], point[2]);
}
