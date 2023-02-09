#include <iostream>
#include "rectangle.h"
#include "parallelogram.h"
#include "triangle.h"
#include "CompositeShape.h"
#include "base-types.h"
#include "shape.h"
#include "printShapes.h"
#include "isoScale.h"

int main()
{
  CompositeShape compositeShape;
  bool correctFigure = false;
  bool correctScale = false;
  bool correctComposite = false;
  int countCorrectFigure = 0;
  int countInvalidFigure = 0;
  std::string figureName = "";
  while (std::cin)
  {
    std::cin >> figureName;
    if (!std::cin)
    {
      break;
    }
    if (figureName == "RECTANGLE" || figureName == "PARALLELOGRAM" || figureName == "TRIANGLE")
    {
      Shape* shape = nullptr;
      try
      {
        if (figureName == "RECTANGLE")
        {
          point_t A{}, B{};
          std::cin >> A.x >> A.y >> B.x >> B.y;
          Shape* shape = new Rectangle(A, B);
          compositeShape.push_back(shape);
          countCorrectFigure++;
          correctFigure = true;
          correctComposite = true;
        }
        else if (figureName == "PARALLELOGRAM")
        {
          point_t A{}, B{}, C{};
          std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
          Shape* shape = new Parallelogram(A, B, C);
          compositeShape.push_back(shape);
          countCorrectFigure++;
          correctFigure = true;
          correctComposite = true;
        }
        else if (figureName == "TRIANGLE")
        {
          point_t A{}, B{}, C{};
          std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
          Shape* shape = new Triangle(A, B, C);
          compositeShape.push_back(shape);
          countCorrectFigure++;
          correctFigure = true;
          correctComposite = true;
        }
      }
      catch (const std::invalid_argument& e)
      {
        correctFigure = false;
        countInvalidFigure++;
        delete[] shape;
        continue;
      }
      catch (...)
      {
        correctComposite = false;
      }
      delete[] shape;
    }
    else if (figureName == "SCALE")
    {
      if (countCorrectFigure != 0)
      {
        correctFigure = true;
      }
      correctScale = true;
      double x = 0.0;
      double y = 0.0;
      std::cin >> x >> y;
      point_t pos{ x, y };
      double k = 0.0;
      std::cin >> k;
      if (!std::cin || k < 0)
      {
        correctScale = false;
        break;
      }
      printShapes(std::cout, compositeShape);
      std::cout << '\n';
      try
      {
        for (size_t i = 0; i < compositeShape.size(); ++i)
        {
          isoScale(compositeShape[i], pos, k);
        }
        correctScale = true;
      }
      catch (...)
      {
        correctScale = false;
      }
      printShapes(std::cout, compositeShape);
      std::cout << '\n';
    }
    else
    {
      correctFigure = true;
      continue;
    }
  }
  if (!correctFigure)
  {
    std::cerr << "ERROR: invalid figure\n";
    return 1;
  }
  if (!correctScale)
  {
    std::cerr << "ERROR: invalid scaling\n";
    return 1;
  }
  if (!correctComposite)
  {
    std::cerr << "ERROR: invalid composite\n";
  }
  if (countInvalidFigure != 0)
  {
    std::cerr << "error...";
  }
  return 0;
}
