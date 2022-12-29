#include <iostream>
#include <iomanip>
#include <cmath>

double sinx(double x, double error, unsigned max_members)
{
  double summ = 0.0;
  double next = x;
  unsigned members = 1;
  long int factorial = 0;
  const double numerator = -1.0 * x * x;

  do
  {
    summ += next;
    factorial = (2 * members * (1 + 2 * members));
    next = next * numerator / factorial;
    members++;
  }
  while (fabs(next) > error || members != max_members);

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
  std::cout << sinx(left_border, error, members) << " " << sin(left_border);
  return 0;
}
