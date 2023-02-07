#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>
#include <stdexcept>
#include "isoscale.h"
#include "compositeshape.h"
#include "rectangle.h"
#include "triangle.h"
#include "complexquad.h"

void printFramePoint(Shape *shape)
{
  std::cout << std::fixed << std::setprecision(1);
  rectangle_t rect = shape->getFrameRect();
  point_t point1{rect.pos.x - 0.5 * rect.width, rect.pos.y - 0.5 * rect.height};
  point_t point2{rect.pos.x + 0.5 * rect.width, rect.pos.y + 0.5 * rect.height};
  std::cout << point1.x << ' ' << point1.y << ' ';
  std::cout << point2.x << ' ' << point2.y;
}
void printAreaAndFlamePoint(CompositeShape &compositeShape)
{
  std::cout << std::fixed << std::setprecision(1) << compositeShape.getArea() << " ";
  printFramePoint(compositeShape[0]);
  for (size_t i = 1; i < compositeShape.size(); ++i)
  {
    std::cout << " ";
    printFramePoint(compositeShape[i]);
  }
  std::cout << "\n";
}

int main()
{
  CompositeShape compositeShape;
  point_t scalecenter;
  double scalek = 0;
  bool isscale = false;
  bool invalidComposite = false;
  do
  {
    std::string name = "";
    std::cin >> name;
    try
    {
      if (name == "RECTANGLE")
      {
        Shape* shape = inputRectangle(std::cin);
        compositeShape.push_back(shape);
      }
      else if (name == "TRIANGLE")
      {
        Shape* shape = inputTriangle(std::cin);
        compositeShape.push_back(shape);
      }
      else if (name == "COMPLEXQUAD")
      {
        Shape* shape = inputComplexquad(std::cin);
        compositeShape.push_back(shape);
      }
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      return 1;
    }
    catch (...)
    {
      invalidComposite = true;
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
  if (!isscale)
  {
    std::cerr << "error";
    return 1;
  }
  if (invalidComposite)
  {
    std::cerr << "error";
  }

  if (!compositeShape.size())
  {
    std::cerr << "error";
    return 1;
  }
  printAreaAndFlamePoint(compositeShape);
  try
  {
    compositeShape.checkIsoScale_(scalecenter, scalek);
  }
  catch(const std::logic_error &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  printAreaAndFlamePoint(compositeShape);
  return 0;
}
