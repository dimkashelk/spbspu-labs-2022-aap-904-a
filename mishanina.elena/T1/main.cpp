#include <iostream>
#include "rectangle.h"
#include "parallelogram.h"
#include "triangle.h"
#include "CompositeShape.h"
#include "base-types.h"
#include "shape.h"
#include "printShapes.h"
#include "isoScale.h"
#include "createPoints.h"
int main()
{
  CompositeShape compositeShape;
  bool correctFigure = false;
  bool correctScale = false;
  bool correctComposite = false;
  bool isAddFigure = false;
  bool hasInvalidFigure = false;
  std::string figureName = "";
  while (std::cin)
  {
    std::cin >> figureName;
    if (!std::cin)
    {
      break;
    }
    if (figureName == "RECTANGLE")
    {
//      point_t A{}, B{};
//      std::cin >> A.x >> A.y >> B.x >> B.y;
//      if (!std::cin)
//      {
//        break;
//      }
      std::size_t size = 4;
      double *coordinates = nullptr;
      try
      {
        coordinates = createCoordinates(std::cin, size);
      }
      catch (const std::invalid_argument &e)
      {
        correctFigure = false;
        continue;
      }
      //point_t *points = nullptr;
      //try
//      {
//      }
//      catch (const std::invalid_argument &e)
//      {
//        correctFigure = false;
//        delete[] coordinates;
//        continue;
//      }

      point_t *points = fillPoints(coordinates, size / 2);
      Shape *shape = nullptr;
      try
      {
        shape = new Rectangle(points[0], points[1]);
//        shape = new Rectangle(A, B);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument &e)
      {
        correctFigure = false;
        hasInvalidFigure= true;
        delete coordinates;
        delete points;
        continue;
      }
      catch (...)
      {
        correctComposite = false;
        delete coordinates;
        delete points;
        delete shape;
      }
      correctFigure = true;
      correctComposite = true;
      isAddFigure = true;
    }
    else if (figureName == "PARALLELOGRAM")
    {
      point_t A{}, B{}, C{};
      std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
      if (!std::cin)
      {
        break;
      }
      Shape *shape = nullptr;
      try
      {
        shape = new Parallelogram(A, B, C);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument &e)
      {
        correctFigure = false;
        hasInvalidFigure= true;
        continue;
      }
      catch (...)
      {
        correctComposite = false;
        delete shape;
      }
      correctFigure = true;
      correctComposite = true;
      isAddFigure = true;
    }
    else if (figureName == "TRIANGLE")
    {
      point_t A{}, B{}, C{};
      std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
      if (!std::cin)
      {
        break;
      }
      Shape *shape = nullptr;
      try
      {
        shape = new Triangle(A, B, C);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument &e)
      {
        correctFigure = false;
        hasInvalidFigure= true;
        continue;
      }
      catch (...)
      {
        correctComposite = false;
        delete shape;
      }
      correctFigure = true;
      correctComposite = true;
      isAddFigure = true;
    }
    else if (figureName == "SCALE")
    {
      if (!isAddFigure)
      {
        std::cerr << "no one figure not add\n";
        return 1;
      }
      correctScale = true;
      double x = 0.0;
      double y = 0.0;
      std::cin >> x >> y;
      if (!std::cin)
      {
        break;
      }
      point_t pos{x, y};
      double k = 0.0;
      std::cin >> k;
      if (!std::cin || k <= 0)
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
      correctFigure= true;
      break;
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
  if (hasInvalidFigure)
  {
    std::cerr << "ERROR: have some wrong figure\n";
  }
  return 0;
}
