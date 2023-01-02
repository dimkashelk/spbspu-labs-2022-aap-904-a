#include "inputrectangle.h"
#include <iostream>

rectangle* inputRectangle(std::istream &in)
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
  return new rectangle(point_t{x1, y1}, point_t{x2, y2});
}
