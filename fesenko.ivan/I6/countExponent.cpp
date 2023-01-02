#include "countExponent.h"
#include <stdexcept>

ElementOfRow::ElementOfRow(double x):
  x(x),
  factorial(1),
  number(1)
{

}

double ElementOfRow::operator()()
{
  x *= x;
  factorial *= number + 1;
  number++;
  return x / factorial;
}

double countExponent(double x, double absError, unsigned numberMax)
{
  ElementOfRow elementOfRow(x);
  double result = 1 + x;
  double element = 0.0;
  for (unsigned i = 1; i < numberMax; i++) {
    element = elementOfRow();
    if (element < absError) {
      return result;
    }
    result += element;
  }
  throw std::logic_error("The specified accuracy has not been achieved\n");
}
