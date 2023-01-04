#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>
#include <stdexcept>
#include "inputrectangle.h"
#include "isoscale.h"
#include "compositeshape.h"
#include "inputtriangle.h"
#include "inputcomplexquad.h"

void printFramePoints(std::ostream & output, const rectangle_t & rectangle)
{
  point_t point1{rectangle.pos.x - 0.5 * rectangle.width, rectangle.pos.y - 0.5 * rectangle.height};
  point_t point2{rectangle.pos.x + 0.5 * rectangle.width, rectangle.pos.y + 0.5 * rectangle.height};
  output << point1.x << ' ' << point1.y << ' ' << point2.x << ' ' << point2.y;
}
void printAreaAndFrames(std::ostream & output, const CompositeShape & tmp, size_t size)
{
  if (!size)
  {
    throw std::invalid_argument("error");
  }
  double summ_area = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    summ_area += tmp[i]->getArea();
  }
  output << summ_area;
  for (size_t i = 0; i < size; ++i)
  {
    printFramePoints(output << ' ', tmp[i]->getFrameRect());
  }
}

int main()
{
  std::string line;
  size_t cap = 10;
  CompositeShape rhs(cap);
  while(std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      try
      {
        shape *shape = inputRectangle(std::cin);
        rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
    }
    if (name == "TRIANGLE")
    {
      try
      {
        shape *shape = inputTriangle(std::cin);
        rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
    }
    if (name == "COMPLEXQUAD")
    {
      try
      {
      shape *shape = inputComplexquad(std::cin);
      rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
    }
    if (name == "SCALE")
    {
      double x = 0.0;
      double y = 0.0;
      double k = 0.0;
      std::cin >> x >> y >> k;
      if (k <= 0)
      {
        std::cout << "incorrect value";
      }
    }
  }
  std::cout << "\n";
  printAreaAndFrames(std::cout << std::fixed << std::setprecision(1), rhs, rhs.size());
  std::cout << "\n";
  printAreaAndFrames(std::cout, rhs, rhs.size());
}
