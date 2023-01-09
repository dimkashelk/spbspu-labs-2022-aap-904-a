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
    try
    {
      if (input == "RECTANGLE")
      {
        compositeShape.safe_push_back(makeRectangle(std::cin));
      }
      if (input == "ELLIPSE")
      {
        compositeShape.safe_push_back(makeEllipse(std::cin));
      }
      if (input == "CONCAVE")
      {
        compositeShape.safe_push_back(makeConcave(std::cin));
      }
      if (input == "RING")
      {
        compositeShape.safe_push_back(makeRing(std::cin));
      }
      if (input == "SCALE")
      {
        scale = getScale(std::cin);
        is_scale = true;
        break;
      }
    }
    catch (const std::invalid_argument &e)
    {
      std::cerr << "\nError: ";
      std::cerr << e.what() << '\n';
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
