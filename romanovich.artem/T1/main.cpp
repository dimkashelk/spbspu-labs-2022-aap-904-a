#include <string>
#include <iostream>
#include <iomanip>
#include "base-types.h"
#include "rectangle.h"
//void buildParallelogram()
//{
//  point_t A{}, B{}, C{}, D{};
//  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
//  D.x = A.x - B.x + C.x;
//  D.y = A.y - B.y + C.y;
//}
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
//void buildConcave()
//{
//  point_t A{}, B{}, C{}, D{};
//  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
//}
int main()
{
  std::string figureName = "";
  std::cin >> figureName;
  if (figureName == "PARALLELOGRAM")
  {
    //buildParallelogram();
  }
  if (figureName == "RECTANGLE")
  {
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
    //buildConcave();
  }
  return 0;
}
