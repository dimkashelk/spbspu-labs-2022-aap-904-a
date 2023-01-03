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
  CompositeShape compositeShape;
  while(std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      shape *shape = inputRectangle();
      compositeShape.push_back(shape);
    }
  }
}
