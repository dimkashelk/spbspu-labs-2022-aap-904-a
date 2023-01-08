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
        std::cerr << "invalid input";
        //return 1;
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
        std::cerr << "invalid input";
        //return 1;
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
        std::cerr << "invalid input";
        //return 1;
      }
    }
    else if (name == "SCALE")
    {
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
        std::cerr << "invalid scaling input";
        //return 1;
      }
      printShapes(compositeShape);
    }
  }
  return 0;
}
