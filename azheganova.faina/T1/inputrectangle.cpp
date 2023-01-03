#include "inputrectangle.h"
#include <iostream>

rectangle* inputRectangle()
{
  point_t x1{};
  point_t y1{};
  point_t x2{};
  point_t y2{};
  std::cin >> x1.x;
  std::cin >> y1.y;
  std::cin >> x2.x;
  std::cin >> y2.y;
  if (!std::cin)
  {
    std::cout << "error";
  }
  return new rectangle[4]{x1, y1, x2, y2};
}
