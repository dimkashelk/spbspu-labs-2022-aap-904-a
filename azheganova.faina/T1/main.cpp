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

double getArea(const CompositeShape &rhs)
{
  double sumarea = 0.0;
  for (size_t i = 0; i < rhs.size(); i++)
  {
    sumarea += rhs[i]->getArea();
  }
  return sumarea;
}

void printFlamePoint(std::ostream & output, const rectangle_t & rectangle)
{
  point_t point1{rectangle.pos.x - 0.5 * rectangle.width, rectangle.pos.y - 0.5 * rectangle.height};
  point_t point2{rectangle.pos.x + 0.5 * rectangle.width, rectangle.pos.y + 0.5 * rectangle.height};
  output << point1.x << ' ' << point1.y << ' ';
  output << point2.x << ' ' << point2.y;
}

void printAreaAndFrames(std::ostream & output, const CompositeShape & rhs)
{
  output << std::setprecision(1) << std::fixed << getArea(rhs);
  for (size_t i = 0; i < rhs.size(); ++i)
  {
    printFlamePoint(output << ' ', rhs[i]->getFrameRect());
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
  printAreaAndFrames(std::cout << std::fixed << std::setprecision(1), shapes);
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
  printAreaAndFrames(std::cout << std::fixed << std::setprecision(1), shapes);
  std::cout << "\n";
  return 0;
}
