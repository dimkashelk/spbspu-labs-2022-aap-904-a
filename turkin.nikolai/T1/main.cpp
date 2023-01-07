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
     try
     {
       if (line == "RECTANGLE")
       {
         compositeShape.push_back(turkin::createRectangle(std::cin));
       }
       if (line == "SQUARE")
       {
         compositeShape.push_back(turkin::createSquare(std::cin));
       }
       if (line == "ELLIPSE")
       {
         compositeShape.push_back(turkin::createEllipse(std::cin));
       }
       if (line == "SCALE")
       {
         scale = turkin::getScale(std::cin);
         isscale = true;
         break;
       }
     }
     catch (const std::logic_error & error)
     {
       std::cerr << error.what() << "\n";
     }
  }
  if (compositeShape.empty())
  {
    std::cerr << "nothing to scaleWithVerify" << "\n";
    return 1;
  }
  if (!isscale)
  {
    std::cerr << "no scaleWithVerify command" << "\n";
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

