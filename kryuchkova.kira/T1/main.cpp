#include <iostream>
#include "shape.h"
#include "base_types.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "composite_shape.h"

void printShapes(const kryuchkova::CompositeShape &compositeShape)
{
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    std::cout << *compositeShape.at(i) << '\n';
  }
}

int main()
{
  std::cout << std::setprecision(1) << std::fixed;
  kryuchkova::CompositeShape compositeShape;
  bool invalidShape = false;
  bool isScaleCalled = false;
  bool invalidScale = false;
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      break;
    }
    if (name == "RECTANGLE")
    {
      try
      {
        kryuchkova::Shape *shape = kryuchkova::inputRectangle(std::cin);
        compositeShape.push_back(shape);
      }
      catch (...)
      {
        invalidShape = true;
      }
    }
    else if (name == "SQUARE")
    {
      try
      {
        kryuchkova::Shape *shape = kryuchkova::inputSquare(std::cin);
        compositeShape.push_back(shape);
      }
      catch (...)
      {
        invalidShape = true;
      }
    }
    else if (name == "CIRCLE")
    {
      try
      {
        kryuchkova::Shape *shape = kryuchkova::inputCircle(std::cin);
        compositeShape.push_back(shape);
      }
      catch (...)
      {
        invalidShape = true;
      }
    }
    else if (name == "SCALE")
    {
      isScaleCalled = true;
      double x = 0.0;
      double y = 0.0;
      std::cin >> x >> y;
      kryuchkova::point_t point(x, y);
      double k = 0.0;
      std::cin >> k;
      printShapes(compositeShape);
      try
      {
        compositeShape.isoScale(point, k);
      }
      catch(...)
      {
        invalidScale = true;
      }
      printShapes(compositeShape);
    }
  }
  if (!isScaleCalled)
  {
    std::cerr << "Scale was not called";
    return 1;
  }
  if (invalidShape)
  {
    std::cerr << "Invalid shape or shapes";
  }
  if (invalidScale)
  {
    std::cerr << "Invalid scaling";
    return 1;
  }
  return 0;
}
