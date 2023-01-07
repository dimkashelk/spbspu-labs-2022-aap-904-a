#include <iostream>
#include "base-types.hpp"

int main()
{
  size_t capacity = 10;
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

        is_scale = true;
      }
      catch (const std::invalid_argument &e)
      {
        std::cerr << e.what() << '\n';
      }
      break;
    }
  }

  return 0;
}
