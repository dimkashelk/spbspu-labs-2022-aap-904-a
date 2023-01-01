#include <string>
#include <iostream>
#include <iomanip>
#include "base-types.h"
#include "rectangle.h"
rectangle_t *extendArray(rectangle_t *rectArray, size_t size, size_t capacity)
{
  if (capacity < size)
  {
    throw std::invalid_argument("Expansion is impossible.");
  }
  rectangle_t *newRectArray = new rectangle_t[capacity];
  for (auto i = rectArray, j = newRectArray; i != rectArray + size; ++i, ++j)
  {
    *j = *i;
  }
  return newRectArray;
}
void buildParallelogram()
{
//  point_t A{}, B{}, C{}, D{};
//  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
//  D.x = A.x - B.x + C.x;
//  D.y = A.y - B.y + C.y;
}
point_t *buildRectangle()
{
  point_t A{}, B{}, C{}, D{};
  std::cin >> A.x >> A.y >> C.x >> C.y;
  B.x = A.x;
  B.y = C.y;
  D.x = C.x;
  D.y = A.y;
  point_t *pointsArray = nullptr;
  try
  {
    pointsArray = new point_t[4]{A, B, C, D};
  }
  catch (...)
  {
    std::cerr << "Error occurred.\n";
  }
  return pointsArray;
}
void buildConcave()
{
//  point_t A{}, B{}, C{}, D{};
//  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
}
int main()
{
  std::string figureName = "";
  size_t capacity = 10;
  rectangle_t *rectArray = new rectangle_t[capacity];
  size_t rectArraySize = 0;
  while (figureName != "SCALE")
  {
    std::cin >> figureName;
    if (rectArraySize >= capacity)
    {
      try
      {
        size_t capacityAdd = 2;
        rectangle_t *extendedRectArray = extendArray(rectArray, rectArraySize, capacity + capacityAdd);
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
      rectArraySize++;
      auto p = std::setprecision(1);
      std::cout << std::fixed;
      point_t *pointsArray = buildRectangle();
      Rectangle rectangle(pointsArray[0], pointsArray[1], pointsArray[2], pointsArray[3]);
      rectangle_t frameRect = rectangle.getFrameRect();
      double frRectAX = frameRect.pos.x - frameRect.width / 2;
      double frRectAY = frameRect.pos.y - frameRect.height / 2;
      double frRectCX = frameRect.pos.x + frameRect.width / 2;
      double frRectCY = frameRect.pos.y + frameRect.height / 2;
      std::cout << p << rectangle.getArea() << " ";
      std::cout << p << frRectAX << " " << p << frRectAY << " " << p << frRectCX << " " << p << frRectCY << "\n";
    }
    if (figureName == "CONCAVE")
    {
      buildConcave();
    }
    if (figureName == "SCALE")
    {
//      point_t *pointsArray = new point_t[4]{{-1.0, -1.0},
//                                            {1.0,  1.0}};
//      Rectangle rectangle(pointsArray[0], pointsArray[1], pointsArray[2], pointsArray[3]);
//      auto p = std::setprecision(1);
//      std::cout << std::fixed;
//      rectangle.isoScale(pointsArray, -1.0, -1.0, 2.0);
//      rectangle_t frameRect = rectangle.getFrameRect();
//      double rectAX = frameRect.pos.x - frameRect.width / 2;
//      double rectAY = frameRect.pos.y - frameRect.height / 2;
//      double rectCX = frameRect.pos.x + frameRect.width / 2;
//      double rectCY = frameRect.pos.y + frameRect.height / 2;
//      std::cout << p << rectAX << " " << p << rectAY << " " << p << rectCX << " " << p << rectCY << "!\n";
    }
  }
  return 0;
}
