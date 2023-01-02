#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>
#include <stdexcept>
#include "base_types.h"
#include "rectangle.h"
#include "inputrectangle.h"
#include "compositeshape.h"
#include "isoscale.h"

int main()
{
  std::string line;
  size_t capacity = 10;
  size_t size = 0;
  shape **shapes = new shape*[capacity];
  while(std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      shapes[size] = inputRectangle(std::cin);
      CompositeShape increaseArr(shape);
    }
  }
}
