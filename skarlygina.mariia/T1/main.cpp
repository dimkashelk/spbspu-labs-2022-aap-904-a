#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "ring.h"

int main()
{
  std::string figure = "";
  double x = 0.0;
  double y = 0.0;

  do 
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      point_t left_down_point{}, right_up_point{};
      try
      {
        std::cin >> left_down_point.x >> left_down_point.y >> right_up_point.x >> right_up_point.y;
        Shape* rectangle = new Rectangle(left_down_point, right_up_point);
      }
      catch (...)
      {
        std::cerr << "Error while reading parameters of the rectangle\n";
        return 2;
      }
    }

    if (figure == "RING")
    {
      //Shape* ring = new Ring();
      return 0;
    }

    if (figure == "ELLIPSE")
    {
      //Shape* ellipse = new Ellipse();
      return 0;
    }
  }
  while (std::cin);
  return 0;
}
