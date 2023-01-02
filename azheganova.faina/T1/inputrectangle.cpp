#include "inputrectangle.h"
#include <iostream>

point_t* inputRectangle()
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  if (!in)
  {
    std::cout << "error";
  }
  return new point_t[4]{x1, x2, x3, x4};
}
