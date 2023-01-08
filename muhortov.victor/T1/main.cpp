#include <iostream>
#include "base-types.hpp"
#include "createShapes.hpp"
#include "printShapes.hpp"
#include "compositeshape.hpp"

int main()
{
  size_t capacity = 10;
  CompositeShape compositeShape(capacity);
  bool is_scale = false;
  scale_t scale = {{0.0, 0.0}, 0.0};
  std::string input = " ";

  while (std::cin)
  {
    std::cin >> input;

    try
    {
      if (input == "RECTANGLE")
      {
        compositeShape.push_back(createRectangle(std::cin));
      }
      if (input == "RING")
      {
        compositeShape.push_back(createRing(std::cin));
      }
      if (input == "CONCAVE")
      {
        compositeShape.push_back(createConcave(std::cin));
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
      std::cerr << e.what() << '\n';
    }
  }

  if (compositeShape.empty())
  {
    std::cerr << "It is nothing to scale\n";
    return 1;
  }
  if (!is_scale)
  {
    std::cerr << "no scale command\n";
    return 1;
  }

  printAreaSum(std::cout, compositeShape);
  std::cout << "\n";

  try
  {
    compositeShape.scale(scale);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  printAreaSum(std::cout, compositeShape);
  std::cout << "\n";

  return 0;
}
