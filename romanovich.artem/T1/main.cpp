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
void buildRectangle()
{
  point_t A{}, B{}, C{}, D{};
  std::cin >> A.x >> A.y >> C.x >> C.y;
  C.x = A.x;
  C.y = B.y;
  D.x = B.x;
  D.y = A.y;
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
    buildRectangle();
  }
  if (figureName == "CONCAVE")
  {
    buildConcave();
  }
  return 0;
}
