#include <string>
#include <iostream>
#include <iomanip>
#include "base-types.h"
#include "rectangle.h"
Rectangle *extendArray(Rectangle *rectArray, size_t size, size_t capacity)
{
  if (capacity < size)
  {
    throw std::invalid_argument("Expansion is impossible.");
  }
  Rectangle *newRectArray = new Rectangle[capacity];
  for (auto i = rectArray, j = newRectArray; i != rectArray + size; ++i, ++j)
  {
    *j = *i;
  }
  return newRectArray;
}
void printLine(Rectangle rectangle)
{
  auto p = std::setprecision(1);
  std::cout << std::fixed;
  rectangle_t frameRect = rectangle.getFrameRect();
  double frRect1X = frameRect.pos.x - frameRect.width / 2;
  double frRect1Y = frameRect.pos.y - frameRect.height / 2;
  double frRect2X = frameRect.pos.x + frameRect.width / 2;
  double frRect2Y = frameRect.pos.y + frameRect.height / 2;
  std::cout << p << rectangle.getArea() << " ";
  std::cout << p << frRect1X << " " << p << frRect1Y << " ";
  std::cout << p << frRect2X << " " << p << frRect2Y << "\n";
}
//
void buildParallelogram()
{
//  point_t A{}, B{}, C{}, D{};
//  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
//  D.x = A.x - B.x + C.x;
//  D.y = A.y - B.y + C.y;
}
//
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
  point_t *pointsArray = nullptr;
//  try
//  {
  pointsArray = new point_t[4]{A, B, C, D};
//  }
//  catch (...)
//  {
//    std::cerr << "Error occurred.\n";
//  }
  return pointsArray;
}
//
void buildConcave()
{
//  point_t A{}, B{}, C{}, D{};
//  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
}
//
int main()
{
  std::string figureName = "";
  size_t capacity = 10, rectArraySize = 0;
  Rectangle *rectArray = nullptr;
  try
  {
    rectArray = new Rectangle[capacity];
  }
  catch (...)
  {
    std::cerr << "Error occurred making rectangle.\n";
  }
  double iScaleX = 0, iScaleY = 0, iScaleK = 1;
  while (std::cin)
  {
    std::cin >> figureName;
    if (rectArraySize >= capacity)
    {
      try
      {
        size_t capacityAdd = 2;
        Rectangle *extendedRectArray = extendArray(rectArray, rectArraySize, capacity + capacityAdd);
        delete[] rectArray;
        rectArray = extendedRectArray;
        extendedRectArray = nullptr;
        capacity += capacityAdd;
      }
      catch (...)
      {
        delete[] rectArray;
        throw std::invalid_argument("Error while extending array.");
      }
    }
    if (figureName == "PARALLELOGRAM")
    {
      buildParallelogram();
    }
    if (figureName == "RECTANGLE")
    {
      point_t *pointsArray = nullptr;
      try
      {
        pointsArray = buildRectangle();
        if (!pointsArray)
        {
          std::cerr << "Error occurred: points does not match the task condition.\n";
          return 0;
        }
      }
      catch (...)
      {
        std::cerr << "Error occurred while building rectangle.\n";
        delete[] pointsArray;
        return 2;
      }
      Rectangle rectangle(pointsArray);
      delete[] pointsArray;
      rectArray[rectArraySize] = rectangle;
      rectArraySize++;
    }
    if (figureName == "CONCAVE")
    {
      buildConcave();
    }
    if (figureName == "SCALE")
    {
      std::cin >> iScaleX >> iScaleY >> iScaleK;
      if (iScaleK <= 0)
      {
        std::cerr << "Negative koeff.\n";
        delete[] rectArray;
        return 2;
      }
    }
  }
  for (size_t i = 0; i < rectArraySize; ++i) //TODO dynamic calculation
  {
    printLine(rectArray[i]);
    //
    //rectArray[i].isoScale(rectArray[i], iScaleX, iScaleY, iScaleK);
    point_t shiftPosition{};
    shiftPosition.x = iScaleX;
    shiftPosition.y = iScaleY;
    rectArray[i].move(shiftPosition);
    double dx = shiftPosition.x - rectArray[i].getFrameRect().pos.x;
    double dy = shiftPosition.y - rectArray[i].getFrameRect().pos.y;
    rectArray[i].scale(iScaleK);
    dx *= iScaleK;
    dy *= iScaleK;
    rectArray[i].move(dx, dy);
    //
    printLine(rectArray[i]);
  }
  delete[] rectArray;
  return 0;
}
