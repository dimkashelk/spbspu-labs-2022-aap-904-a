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
  size_t capacity = 10;
  CompositeShape compositeShape(capacity);
  point_t *arr = nullptr;
  while(std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      arr = inputRectangle();
      shape *shape = new rectangle(arr);
      compositeShape.push_back(shape);
    }
  }
}
