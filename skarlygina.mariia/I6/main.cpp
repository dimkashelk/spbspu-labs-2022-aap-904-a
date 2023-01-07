#include <iostream>
#include <cmath>
#include <iomanip>
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
    } while (std::fabs(next) > error || members != max_members);

    return summ;
}

void printTableRow(std::ostream& out, double x, double error, unsigned members)
{
    out << std::setw(5) << x << ' ';
    out << std::setw(10) << std::setprecision(5) << sinx(x, error, members) << ' ';
    out << std::setw(10) << std::setprecision(5) << std::sin(x) << '\n';
}

void printTable(std::ostream& out, double error, unsigned members, double left_border, double right_border, double step)
{
    for (double x = left_border; x <= right_border; x = x + step)
    {
        printTableRow(out, x, error, members);
        if (x + step >= right_border)
        {
            printTableRow(out, right_border, error, members);
        }
    }
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
  printTable(std::cout, error, members, left_border, right_border, step);
  return 0;
}
