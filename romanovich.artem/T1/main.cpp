#include <string>
#include <iostream>
#include "base-types.h"
void buildParallelogram()
{
  point_t A{}, B{}, C{}, D{};
  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
  D.x = A.x - B.x + C.x;
  D.y = A.y - B.y + C.y;
}
point_t * buildRectangle()
{
  point_t A{}, B{}, C{}, D{};
  std::cin >> A.x >> A.y >> C.x >> C.y;
  C.x = A.x;
  C.y = B.y;
  D.x = B.x;
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
  point_t A{}, B{}, C{}, D{};
  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
}
int main()
{
  std::string figureName = "";
  std::cin >> figureName;
  if (figureName == "PARALLELOGRAM")
  {
    buildParallelogram();
  }
  if (figureName == "RECTANGLE")
  {
    point_t *pointsArray = buildRectangle();
  }
  if (figureName == "CONCAVE")
  {
    buildConcave();
  }
  return 0;
}
