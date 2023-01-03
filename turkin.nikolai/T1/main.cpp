#include <iostream>
#include <iomanip>
#include "shapesPatterns.h"
#include "readShapes.h"
#include "isoscale.h"

int main()
{
  size_t i = 0;
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
         shapes[i] = turkin::createRectangle(std::cin);
         i++;
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
         shapes[i] = turkin::createSquare(std::cin);
         i++;
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
         shapes[i] = turkin::createEllipse(std::cin);
         i++;
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
         for (size_t k = 0; k < i; k++)
         {
           delete shapes[k];
         }
         delete [] shapes;
         return 1;
       }
       break;
     }
  }

  if (i == 0)
  {
    std::cerr << "nothing to scale" << "\n";
    delete [] shapes;
    return 1;
  }
  if (!isscale)
  {
    std::cerr << "no scale command" << "\n";
    for (size_t k = 0; k < i; k++)
    {
      delete shapes[k];
    }
    delete [] shapes;
    return 1;
  }

  double sum = 0.0;
  for (size_t k = 0; k < i; k++)
  {
    sum = sum + shapes[k]->getArea();
  }
  std::cout << std::setprecision(1) << std::fixed << sum;
  for (size_t k = 0; k < i; k++)
  {
    turkin::rectangle_t buffer = shapes[k]->getFrameRect();
    std::cout << " " << buffer.position.x - (buffer.width / 2.0) << " ";
    std::cout << buffer.position.y - (buffer.height / 2.0) << " ";
    std::cout << buffer.position.x + (buffer.width / 2.0) << " ";
    std::cout << buffer.position.y + (buffer.height / 2.0);
  }
  std::cout << "\n";
  sum = 0.0;
  for (size_t k = 0; k < i; k++)
  {
    chemodurov::isoScale(shapes[k], scale.position, scale.scale);
  }
  for (size_t k = 0; k < i; k++)
  {
    sum = sum + shapes[k]->getArea();
  }
  std::cout << std::setprecision(1) << std::fixed << sum;
  for (size_t k = 0; k < i; k++)
  {
    turkin::rectangle_t buffer = shapes[k]->getFrameRect();
    std::cout << " " << buffer.position.x - (buffer.width / 2.0) << " ";
    std::cout << buffer.position.y - (buffer.height / 2.0) << " ";
    std::cout << buffer.position.x + (buffer.width / 2.0) << " ";
    std::cout << buffer.position.y + (buffer.height / 2.0);
  }
  std::cout << "\n";
  for (size_t k = 0; k < i; k++)
  {
    delete shapes[k];
  }
  delete [] shapes;
  return 0;
}
