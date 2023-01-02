#include <iostream>
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"

int main()
{
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      std::cout << "Error in name/n";
      return 1;
    }
    if (name == "RECTANGLE")
    {
      try
      {
        double x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (!std::cin)
        {
          std::cout << "Error in coordinates/n";
          return 1;
        }
        tarasenko::point_t point_ld(x1,y1);
        tarasenko::point_t point_ru(x2,y2);
        tarasenko::Rectangle rect(point_ld, point_ru);
      }
      catch (const std::invalid_argument & e)
      {
        return 1;
      }
    }
  }
}