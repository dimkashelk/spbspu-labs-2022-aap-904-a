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
      point_t center{};
      double radius_small, radius_big;
      try
      {
        std::cin >> center.x >> center.y >> radius_small >> radius_big;
        Shape* ring = new Ring(center, radius_small, radius_big);
      }
      catch (...)
      {
        std::cerr << "Error while reading parameters of the ring\n";
        return 2;
      }
    }

    if (figure == "ELLIPSE")
    {
      double radius_vertical, radius_horizontal;
      point_t center;
      try
      {
        std::cin >> center.x >> center.y >> radius_vertical >> radius_horizontal;
        Shape* ellipse = new Ellipse(center, radius_vertical, radius_horizontal);
      }
      catch (...)
      {
          std::cerr << "Error while reading parameters of the ellipse\n";
          return 2;
      }
    }
  }
  while (std::cin);
  return 0;
}
