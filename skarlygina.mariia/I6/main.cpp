#include <iostream>

double sinx(double x, double error, unsigned max_members)
{
  double summ = 0.0;
  double next = 0.0;
  unsigned members = 0;
  do
  {
    members++;
  } 
  while (members != max_members || next > error);
  return summ;
}

int main()
{
  const double step = 0.05;
  const double error = 0.0001;
  double left_border = 0.0;
  double right_border = 0.0;
  unsigned members = 0;
  std::cin >> left_border >> right_border >> members;
  if (!std::cin || left_border >= right_border || left_border <= -1.0 || right_border >= 1.0)
  {
    std::cerr << "Error: false parameters";
    return 1;
  }
  return 0;
}
