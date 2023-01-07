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

void printLeftDownAndRightUp(std::ostream & output, const rectangle_t & rectangle)
{
  point_t point1{rectangle.pos.x - 0.5 * rectangle.width, rectangle.pos.y - 0.5 * rectangle.height};
  point_t point2{rectangle.pos.x + 0.5 * rectangle.width, rectangle.pos.y + 0.5 * rectangle.height};
  output << point1.x << ' ' << point1.y << ' ';
  output << point2.x << ' ' << point2.y;
}

void printAreaAndFrames(std::ostream & output, const CompositeShape & shapes, size_t size)
{
  double summarea = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    summarea += shapes[i]->getArea();
  }
  output << summarea;
  for (size_t i = 0; i < size; ++i)
  {
    printLeftDownAndRightUp(output << ' ', shapes[i]->getFrameRect());
  }
}

int main()
{
  std::string line;
  size_t cap = 10;
  CompositeShape shapes(cap);
  point_t scalecenter;
  double scalek = 0;
  bool isscale = false;
  bool isfigure = false;
  do
  {
    std::string name = "";
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      isfigure = true;
      try
      {
        Shape *shape = inputRectangle(std::cin);
        shapes.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
      continue;
    }
    if (name == "TRIANGLE")
    {
      isfigure = true;
      try
      {
        Shape *shape = inputTriangle(std::cin);
        shapes.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
      continue;
    }
    if (name == "COMPLEXQUAD")
    {
      isfigure = true;
      try
      {
        Shape *shape = inputComplexquad(std::cin);
        shapes.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        std::cerr << e.what() << "\n";
        continue;
      }
      continue;
    }
    if (name == "SCALE")
    {
      isscale = true;
      double x = 0.0;
      double y = 0.0;
      double k = 0.0;
      std::cin >> x >> y >> k;
      if (k <= 0)
      {
        std::cerr << "incorrect value";
        return 1;
      }
      scalecenter = {x, y};
      scalek = k;
      break;
    }
  }
  while(std::cin);
  if (!(isscale && isfigure))
  {
    return 1;
  }
  printAreaAndFrames(std::cout << std::fixed << std::setprecision(1), shapes, shapes.size());
  std::cout << "\n";
  try
  {
    for (size_t i = 0; i < shapes.size(); ++i)
    {
      isoScale(shapes[i], scalecenter, scalek);
    }
  }
  catch(const std::logic_error &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  printAreaAndFrames(std::cout << std::fixed << std::setprecision(1), shapes, shapes.size());
  std::cout << "\n";
  return 0;
}
