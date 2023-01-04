#include "inputcomplexquad.h"
#include <iostream>

complexquad* inputComplexquad(std::istream &input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  double x4 = 0.0;
  double y4 = 0.0;
  point_t point[4];
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  point[0] = point_t {x1, y1};
  point[1] = point_t {x2, y2};
  point[2] = point_t {x3, y3};
  point[3] = point_t {x4, y4};
  if (!input)
  {
    std::cout << "error";
  }
  return new complexquad(point[0], point[1], point[2], point[3]);
}
