#include <string>
#include <iostream>
#include <iomanip>
#include "base-types.h"
#include "rectangle.h"
#include "parallelogram.h"
#include "compositeshape.h"
#include "concave.h"
void printLine(Shape *shape)
{
  auto p = std::setprecision(1);
  std::cout << std::fixed;
  rectangle_t frameRect = shape->getFrameRect();
  double frRect1X = frameRect.pos.x - frameRect.width / 2;
  double frRect1Y = frameRect.pos.y - frameRect.height / 2;
  double frRect2X = frameRect.pos.x + frameRect.width / 2;
  double frRect2Y = frameRect.pos.y + frameRect.height / 2;
  std::cout << p << frRect1X << " " << p << frRect1Y << " ";
  std::cout << p << frRect2X << " " << p << frRect2Y;
}
point_t *buildParallelogram()
{
  point_t A{}, B{}, C{}, D{};
  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
  D.x = A.x - B.x + C.x;
  D.y = A.y - B.y + C.y;
  return new point_t[4]{A, B, C, D};
}
point_t *buildRectangle()
{
  point_t A{}, B{}, C{}, D{};
  std::cin >> A.x >> A.y >> C.x >> C.y;
  if (A.x >= C.x || A.y >= C.y)
  {
    return nullptr;
  }
  B.x = A.x;
  B.y = C.y;
  D.x = C.x;
  D.y = A.y;
  return new point_t[4]{A, B, C, D};
}
point_t *buildConcave()
{
  point_t A{}, B{}, C{}, D{};
  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
  return new point_t[4]{A, B, C, D};
}
int main()
{
  std::string figureName = "";
  size_t compShapeCapacity = 10;
  CompositeShape compositeShape(compShapeCapacity);
  bool badFigure = false;
  bool figureCommand = false;
  bool scaleCommand = false;
  double iScaleX = 0, iScaleY = 0, iScaleK = 1;
  while (std::cin)
  {
    std::cin >> figureName;
    if (badFigure)
    {
      badFigure = false;
      std::cerr << "Error occurred: points does not match the task condition.\n";
    }
    if (figureName == "PARALLELOGRAM")
    {
      figureCommand = true;
      point_t *pointsArray = nullptr;
      try
      {
        if (!pointsArray)
        {
          badFigure = true;
        }
        pointsArray = buildParallelogram();
        Shape *shape = new Parallelogram(pointsArray);
        compositeShape.push_back(shape);
        delete[] pointsArray;
      }
      catch (...)
      {
        std::cerr << "Error occurred while building parallelogram.\n";
        delete[] pointsArray;
        return 2;
      }
    }
    if (figureName == "RECTANGLE")
    {
      figureCommand = true;
      point_t *pointsArray = nullptr;
      try
      {
        pointsArray = buildRectangle();
        if (!pointsArray)
        {
          badFigure = true;
        }
        else
        {
          Shape *shape = new Rectangle(pointsArray);
          compositeShape.push_back(shape);
        }
        delete[] pointsArray;
      }
      catch (...)
      {
        std::cerr << "Error occurred while building rectangle.\n";
        delete[] pointsArray;
        return 2;
      }
    }
    if (figureName == "CONCAVE")
    {
      figureCommand = true;
      point_t *pointsArray = nullptr;
      try
      {
        pointsArray = buildConcave();
        Concave *concave = new Concave(pointsArray);
        if (!concave->goodConcaveInput())
        {
          badFigure = true;
        }
        else
        {
          Shape *shape = new Concave(pointsArray);
          compositeShape.push_back(shape);
        }
        delete concave;
        delete[] pointsArray;
      }
      catch (...)
      {
        std::cerr << "Error occurred while building parallelogram.\n";
        delete[] pointsArray;
        return 2;
      }
    }
    if (figureName == "SCALE")
    {
      scaleCommand = true;
      std::cin >> iScaleX >> iScaleY >> iScaleK;
      if (iScaleK <= 0)
      {
        std::cerr << "Negative koeff.\n";
        return 2;
      }
    }
  }
  if (!(scaleCommand && figureCommand))
  {
    return 2;
  }
  auto p = std::setprecision(1);
  std::cout << std::fixed;
  std::cout << p << compositeShape.getArea() << " ";
  printLine(compositeShape[0]);
  for (size_t i = 1; i < compositeShape.size(); ++i)
  {
    std::cout << " ";
    printLine(compositeShape[i]);
  }
  for (size_t i = 0; i < compositeShape.size(); ++i)
  {
    compositeShape.isoScale(*compositeShape[i], iScaleX, iScaleY, iScaleK);
  }
  std::cout << "\n";
  double scaledArea = 0;
  for (size_t i = 0; i < compositeShape.size(); ++i)
  {
    scaledArea += compositeShape[i]->getArea();
  }
  std::cout << p << scaledArea << " ";
  printLine(compositeShape[0]);
  for (size_t i = 1; i < compositeShape.size(); ++i)
  {
    std::cout << " ";
    printLine(compositeShape[i]);
  }
  std::cout << "\n";
  return 0;
}
