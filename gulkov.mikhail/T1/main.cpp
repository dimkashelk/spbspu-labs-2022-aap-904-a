#include <iostream>
#include "Base-types.hpp"
#include "MakeShapes.hpp"
#include "PrintShapes.hpp"
#include "CompositeShape.hpp"

int main()
{
  size_t capacity = 10;
  bool is_scale = false;
  std::string input = " ";

  CompositeShape compositeShape(capacity);
  scale_t scale = {{0.0, 0.0}, 0.0};

  while (std::cin)
  {
    std::cin >> input;

    if (input == "RECTANGLE")
    {
      try
      {
        compositeShape.push_back(makeRectangle(std::cin));
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "\nError: ";
        std::cerr << e.what() << '\n';
      }
    }
    else if (input == "ELLIPSE")
    {
      try
      {
        compositeShape.push_back(makeEllipse(std::cin));
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "\nError: ";
        std::cerr << e.what() << '\n';
      }
    }
    else if (input == "CONCAVE")
    {
      try
      {
        compositeShape.push_back(makeConcave(std::cin));
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "\nError: ";
        std::cerr << e.what() << '\n';
      }
    }
    else if (input == "SCALE")
    {
      try
      {
        scale = getScale(std::cin);
        is_scale = true;
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << "\nError: ";
        std::cerr << e.what() << '\n';
      }
      break;
    }
  }

  if (compositeShape.empty())
  {
    std::cerr << "\nError: nothing to scale\n";
    return 1;
  }
  if (!is_scale)
  {
    std::cerr << "\nError: no scale command\n";
    return 1;
  }

  printShapesArea(std::cout, compositeShape);
  std::cout << "\n";
  try
  {
    compositeShape.scale(scale);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << "\nError:\n";
    std::cerr << e.what() << '\n';
    return 1;
  }

  printShapesArea(std::cout, compositeShape);
  std::cout << "\n";

  return 0;
}
