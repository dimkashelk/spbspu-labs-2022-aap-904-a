double exponenta(double x, double absError, unsigned numberMax)
{
  double res = 0.0;
  unsigned members = 0;
  double sum = 0.0;
  double divicible = x * (-1);
  unsigned factorial = 2;
  unsigned divider = 1;
  do
  {
    sum = divicible / divider;
    res += sum;
    members ++;
    divicible *= x * (-1);
    divider *= factorial;
    factorial ++;
  }
  while (members < numberMax || sum > absError);
  return res;
}