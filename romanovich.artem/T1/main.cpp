#include <string>
#include <iostream>
void buildParallelogram()
{
  double xa, ya, xb, yb, xc, yc = 0;
  std::cin >> xa >> ya >> xb >> yb >> xc >> yc;
  double xd = xa - xb + xc;
  double yd = ya - yb + yc;
  std::cout << xd << " " << yd;
}
void scale(double x, double y, double k)
{
  if (k > 0)
  {
  }
}
// PARALLELOGRAM, CONCAVE
int main()
{
  std::string figureName = "";
  std::cin >> figureName;
  std::cout << figureName << "\n";
  if (figureName == "PARALLELOGRAM")
  {
    buildParallelogram();
  }
  return 0;
}
