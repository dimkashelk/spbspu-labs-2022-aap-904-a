#include "inputrectangle.h"
#include <iostream>

point_t* inputRectangle()
{
  point_t x1{};
  point_t y1{};
  point_t x2{};
  point_t y2{};
  std::cin >> x1;
  std::cin >> y1;
  std::cin >> x2;
  std::cin >> y2;
  if (!std::cin)
  {
    std::cout << "error";
  }
  return new point_t[4]{x1, y1, x2, y2};
}
