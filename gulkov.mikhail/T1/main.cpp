#include <iostream>
#include "Base-types.hpp"
#include "IsoScale.hpp"
#include "GetShapes.hpp"
#include "PrintCoordinates.hpp"

int main()
{
  size_t size = 0;
  std::string input;
  bool isscale = false;
  scale_t scale = {{0.0, 0.0}, 0.0};

  Shape **shapes = new Shape *[10];

  while (std::cin)
  {
    std::cin >> input;
    if (input == "RECTANGLE")
    {
      try
      {
        shapes[size] = makeRectangle(std::cin);
        ++size;
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "Error: \n";
        std::cerr << e.what() << "\n";
      }
    }
    if (input == "ELLIPSE")
    {
      try
      {
        shapes[size] = makeEllipse(std::cin);
        ++size;
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "Error: \n";
        std::cerr << e.what() << "\n";
      }
    }
    if (input == "CONCAVE")
    {
      try
      {
        shapes[size] = makeConcave(std::cin);
        ++size;
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "Error: \n";
        std::cerr << e.what() << "\n";
      }
    }
    if (input == "SCALE")
    {
      try
      {
        scale = calcScale(std::cin);
        isscale = true;
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "Error: \n";
        std::cerr << e.what() << "\n";
        for (size_t i = 0; i < size; i++)
        {
          delete shapes[i];
        }
        delete[] shapes;
        return 1;
      }
      break;
    }
  }

  if (size == 0)
  {
    std::cerr << "Error: nothing to scale\n";
    delete[] shapes;
    return 1;
  }
  if (!isscale)
  {
    std::cerr << "no scale command" << "\n";
    for (size_t k = 0; k < size; k++)
    {
      delete shapes[k];
    }
    delete[] shapes;
    return 1;
  }

  printAreaPoints(std::cout, shapes, size);
  for (size_t k = 0; k < size; k++)
  {
    try
    {
      isotropicScale(shapes[k], scale);
    }
    catch (const std::logic_error &error)
    {
      std::cerr << error.what() << "\n";
    }
  }
  printAreaPoints(std::cout, shapes, size);
  for (size_t k = 0; k < size; k++)
  {
    delete shapes[k];
  }
  delete[] shapes;
  return 0;
}
