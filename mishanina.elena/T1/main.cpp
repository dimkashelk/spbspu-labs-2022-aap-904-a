#include <iostream>
#include "rectangle.h"
#include "parallelogram.h"
#include "triangle.h"
#include "CompositeShape.h"

void printShapes(const CompositeShape& compositeShape)
{
  std::cout << compositeShape.getArea();
  for (std::size_t i = 0; i < compositeShape.size(); i++)
  {
    std::cout << ' ' << *compositeShape.at(i);
  }
}

int main()
{
  CompositeShape compositeShape;
  bool correctFigure = false;
  bool correctScale = false;
  while (std::cin)
  {
    std::string figureName = "";
    std::cin >> figureName;
    if (!std::cin)
    {
      std::cerr << "ERROR: invalid input\n";
      correctFigure = false;
      break;
    }
    if (figureName == "RECTANGLE" || figureName == "PARALLELOGRAM" || figureName == "TRIANGLE")
    {
      correctFigure = true;
      Shape* shape = nullptr;
      try
      {
        if (figureName == "RECTANGLE")
        {
          try
          {
            point_t A{}, B{};
            std::cin >> A.x >> A.y >> B.x >> B.y;
            Shape* shape = new Rectangle(A, B);
            compositeShape.push_back(shape);
          }
          catch (...)
          {
            correctFigure = false;
            std::cerr << "invalid rectangle\n";
          }
        }
        else if (figureName == "PARALLELOGRAM")
        {
          correctFigure = true;
          try
          {
            point_t A{}, B{}, C{};
            std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
            Shape* shape = new Parallelogram(A, B, C);
            compositeShape.push_back(shape);
          }
          catch (...)
          {
            correctFigure = false;
            std::cerr << "invalid parallelogram\n";
          }
        }
        else if (figureName == "TRIANGLE")
        {
          correctFigure = true;
          try
          {
            point_t A{}, B{}, C{};
            std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
            Shape* shape = new Triangle(A, B, C);
            compositeShape.push_back(shape);
          }
          catch (...)
          {
            correctFigure = false;
            std::cerr << "invalid triangle\n";
          }
        }
      }
      catch (...)
      {
        correctFigure = false;
        std::cerr << "Invalid figure\n";
        delete[] shape;
        break;
      }
      delete[] shape;
    }
    else if (figureName == "SCALE")
    {
      correctScale = true;
      double k = 0;
      std::cin >> k;
      if (!std::cin)
      {
        std::cerr << "ERROR: invalid input k\n";
        break;
      }
      printShapes(compositeShape);
      std::cout << '\n';
      try
      {
        compositeShape.scale(k);
      }
      catch (...)
      {
        std::cerr << "invalid scale\n";
        correctScale = false;
      }
      printShapes(compositeShape);
      std::cout << '\n';
    }
    else
    {
      correctFigure = false;
      std::cerr << "ERROR: no such figure\n";
      break;
    }
    if (correctFigure == false || correctScale == false)
    {
      std::cerr << "ERROR: correctFigure == false || correctScale == false\n";
      return 1;
    }
  }
  return 0;
}
