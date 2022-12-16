#include <iostream>
#include <cmath>
double var15(double x, double absError, int numberMax)
{
  if (x <= -1 || x >= 1)
  {
    throw std::invalid_argument("x is invalid");
  }
  double sign = -1;
  double xInPow = 1, result = 0;
  bool flag = false;
  for (int i = 0; i < numberMax; i++)
  {
    sign *= -1;
    int con = (i + 1) * (i + 2) / 2;
    double addend = sign * con * xInPow;
    if (abs(addend) < absError)
    {
      flag = true;
      break;
    }
    result += addend;
    xInPow *= x;
  }
  if (flag == false)
  {
    throw std::invalid_argument("invalid numberMax");
  }
  return result;
}
int main()
{
  double absError = 0.01;
  int numberMax = 150;
  double start = -0.85,
    end = 0.85,
    step = 0.1;
  for (double i = start; i <= end; i += step)
  {
    std::cout << i << " : "
              << (1 / pow(1 + i, 3))
              << " : " << var15(i, absError, numberMax) << std::endl;
  }
  system("pause");
  return 0;
}