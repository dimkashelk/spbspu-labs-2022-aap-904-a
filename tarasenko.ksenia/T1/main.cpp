#include <iostream>
#include <stdexcept>
#include "rectangle.hpp"
#include "compositeshape.hpp"
#include "inputshape.hpp"
#include "isoscale.hpp"
#include "outputareaandfaramerect.hpp"

int main()
{
  bool errors = false;
  bool shape_was = false;
  bool scale_was = false;
  tarasenko::CompositeShape compositeShape;
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      std::cerr << "Error in name\n";
      break;
    }
    if (name == "RECTANGLE")
    {
      try
      {
        tarasenko::Shape * shape = tarasenko::inputRectangle(std::cin);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument & e)
      {
        errors = true;
      }
      shape_was = true;
    }
    else if (name == "TRIANGLE")
    {
      try
      {
        tarasenko::Shape * shape = tarasenko::inputTriangle(std::cin);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument & e)
      {
        errors = true;
      }
      shape_was = true;
    }
    else if (name == "COMPLEXQUAD")
    {
      try
      {
        tarasenko::Shape * shape = tarasenko::inputComplexquad(std::cin);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument & e)
      {
        errors = true;
      }
      shape_was = true;
    }
    else if (name == "SCALE")
    {
      if (!shape_was)
      {
        std::cout << "The shape was not called\n";
        return 1;
      }
      scale_was = true;
      double x = 0.0;
      double y = 0.0;
      double k = 0.0;
      std::cin >> x >> y >> k;
      if (!std::cin)
      {
        std::cerr << "Error\n";
      }
      tarasenko::point_t center_scale(x, y);
      tarasenko::outputAreaAndFrameRect(std::cout, compositeShape);
      std::cout << "\n";
      try
      {
        for (size_t i = 0; i < compositeShape.size(); i++)
        {
          isoScale(compositeShape[i], center_scale, k);
        }
      }
      catch (std::invalid_argument & e)
      {
        std::cerr << "Error: ";
        std::cerr << e.what() << "\n";
        return 1;
      }
      tarasenko::outputAreaAndFrameRect(std::cout, compositeShape);
      std::cout << "\n";
      if (errors)
      {
        errors = false;
        std::cerr << "Errors in shapes\n";
      }
      break;
    }
    else
    {
      double skip = 0.0;
      while (std::cin)
      {
        std::cin >> skip;
      }
      std::cin.clear();
    }
  }
  if (!scale_was)
  {
    std::cout << "The SCALE was not called\n";
    return 1;
  }
}
