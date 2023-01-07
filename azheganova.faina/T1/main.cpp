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

void printFlamePoint(Shape *shape)
{
  auto set = std::setprecision(1);
  std::cout << std::fixed;
  rectangle_t rectangle = shape->getFrameRect();
  double point1 = rectangle.pos.x - 0.5 * rectangle.width;
  double point2 = rectangle.pos.y - 0.5 * rectangle.height;
  double point3 = rectangle.pos.x + 0.5 * rectangle.width;
  double point4 = rectangle.pos.y + 0.5 * rectangle.height;
  std::cout  << set << point1 << ' ' << set << point2 << ' ';
  std::cout  << set << point3 << ' ' << set << point4;
}

int main()
{
  size_t cap = 10;
  CompositeShape compositeShape(cap);
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
        compositeShape.push_back(shape);
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
        compositeShape.push_back(shape);
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
        compositeShape.push_back(shape);
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
    std::cerr << "error";
    return 1;
  }
  if (!compositeShape.size())
  {
    std::cerr << "error";
    return 1;
  }
  auto set = std::setprecision(1);
  std::cout << std::fixed << set << compositeShape.getArea() << " ";
  printFlamePoint(compositeShape[0]);
  for (size_t i = 1; i < compositeShape.size(); ++i)
  {
    std::cout << " ";
    printFlamePoint(compositeShape[i]);
  }
  std::cout << "\n";
  try
  {
    for (size_t i = 0; i < compositeShape.size(); ++i)
    {
      isoScale(compositeShape[i], scalecenter, scalek);
    }
  }
  catch(const std::logic_error &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << std::fixed << set << compositeShape.getArea() << " ";
  printFlamePoint(compositeShape[0]);
  for (size_t i = 1; i < compositeShape.size(); ++i)
  {
    std::cout << " ";
    printFlamePoint(compositeShape[i]);
  }
  std::cout << "\n";
  return 0;
}
