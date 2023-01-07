#include <iostream>
#include "base-types.h"
#include "readWriteShapes.h"
#include "compositeShape.h"

int main()
{
  const size_t basicCapacity = 10;
  turkin::CompositeShape compositeShape(basicCapacity);
  std::string line;
  turkin::scale_t scale = {{0.0, 0.0}, 2.0};
  bool isscale = false;
  while (std::cin)
  {
     std::cin >> line;
     if (line == "RECTANGLE")
     {
       try
       {
         compositeShape.push_back(turkin::createRectangle(std::cin));
       }
       catch (const std::logic_error & error)
       {
         std::cerr << error.what() << "\n";
       }
     }
     if (line == "SQUARE")
     {
       try
       {
         compositeShape.push_back(turkin::createSquare(std::cin));
       }
       catch (const std::logic_error & error)
       {
         std::cerr << error.what() << "\n";
       }
     }
     if (line == "ELLIPSE")
     {
       try
       {
         compositeShape.push_back(turkin::createEllipse(std::cin));
       }
       catch (const std::logic_error & error)
       {
         std::cerr << error.what() << "\n";
       }
     }
     if (line == "SCALE")
     {
       try
       {
         scale = turkin::getScale(std::cin);
         isscale = true;
       }
       catch (const std::logic_error & error)
       {
         std::cerr << error.what() << "\n";
         return 1;
       }
       break;
     }
  }
  if (compositeShape.empty())
  {
    std::cerr << "nothing to scale" << "\n";
    return 1;
  }
  if (!isscale)
  {
    std::cerr << "no scale command" << "\n";
    return 1;
  }
  turkin::printAreaPoints(std::cout, compositeShape);
  try
  {
    compositeShape.scale(scale);
  }
  catch (const std::logic_error & error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  turkin::printAreaPoints(std::cout, compositeShape);
  return 0;
}

