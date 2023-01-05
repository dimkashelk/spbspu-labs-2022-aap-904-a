#include <iostream>
#include "base-types.h"
#include "readWriteShapes.h"
#include "isoscale.h"

int main()
{
  size_t size = 0;
  auto ** shapes = new turkin::Shape*[10];
  std::string line;
  turkin::scale_t scale = {{0.0, 0.0}, 0.0};
  bool isscale = false;
  while (std::cin)
  {
     std::cin >> line;
     if (line == "RECTANGLE")
     {
       try
       {
         shapes[size] = turkin::createRectangle(std::cin);
         size++;
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
         shapes[size] = turkin::createSquare(std::cin);
         size++;
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
         shapes[size] = turkin::createEllipse(std::cin);
         size++;
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
         for (size_t k = 0; k < size; k++)
         {
           delete shapes[k];
         }
         delete [] shapes;
         return 1;
       }
       break;
     }
  }

  if (size == 0)
  {
    std::cerr << "nothing to scale" << "\n";
    delete [] shapes;
    return 1;
  }
  if (!isscale)
  {
    std::cerr << "no scale command" << "\n";
    for (size_t k = 0; k < size; k++)
    {
      delete shapes[k];
    }
    delete [] shapes;
    return 1;
  }

  turkin::printAreaPoints(std::cout, shapes, size);
  for (size_t k = 0; k < size; k++)
  {
    try
    {
      turkin::isoScale(shapes[k], scale);
    }
    catch (const std::logic_error & error)
    {
      std::cerr << error.what() << "\n";
    }
  }
  turkin::printAreaPoints(std::cout, shapes, size);
  for (size_t k = 0; k < size; k++)
  {
    delete shapes[k];
  }
  delete [] shapes;
  return 0;
}

