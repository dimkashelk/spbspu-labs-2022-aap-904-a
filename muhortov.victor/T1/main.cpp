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

    if (input == "RECTANGLE")
    {
      try
      {
        compositeShape.push_back(createRectangle(std::cin));
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else if (input == "RING")
    {
      try
      {
        compositeShape.push_back(createRing(std::cin));
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << e.what() << '\n';
      }
    }
    else if (input == "CONCAVE")
    {
      try
      {
        compositeShape.push_back(createConcave(std::cin));
      }
      catch (const std::invalid_argument &e)
      {
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
        std::cerr << e.what() << '\n';
      }
      break;
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

  return 0;
}
