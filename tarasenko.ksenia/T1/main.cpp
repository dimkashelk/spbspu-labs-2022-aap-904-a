#include <iostream>
#include <stdexcept>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"
#include "compositeshape.hpp"
#include "inputshape.hpp"
#include "outputframerect.hpp"
#include "isoscale.hpp"

int main()
{
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      std::cout << "Error in name/n";
      break;
    }
    tarasenko::CompositeShape compositeShape;
    if (name == "RECTANGLE")
    {
      try
      {
        tarasenko::Shape * shape = tarasenko::inputRectangle(std::cin);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument & e)
      {
        return 1;
      }
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
        return 1;
      }
    }
    else if (name == "COMPLEXQUAD")
    {
      tarasenko::Shape * shape = tarasenko::inputComplexquad(std::cin);
      compositeShape.push_back(shape);
    }
    else if (name == "SCALE")
    {
      //outputShape
      try
      {
        double x = 0;
        double y = 0;
        double k = 0;
        std::cin >> x >> y >> k;
        tarasenko::point_t center_scale(x, y);
        for (size_t i = 0; i < compositeShape.size_; i++)
        {
          isoScale(compositeShape.shapes[i], center_scale, k);
        }
      }
      catch (std::invalid_argument & e)
      {

      }
    }
    else
    {
      return 1;
    }
  }
}