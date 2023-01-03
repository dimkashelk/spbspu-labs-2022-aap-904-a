#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>
#include <stdexcept>
#include "inputrectangle.h"
#include "compositeshape.h"

int main()
{
  std::string line;
  CompositeShape rhs;
  while(std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      shape *shape = inputRectangle(std::cin);
      rhs.push_back(shape);
    }
  }
}
