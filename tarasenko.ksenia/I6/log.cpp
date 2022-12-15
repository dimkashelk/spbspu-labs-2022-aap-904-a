#include <cmath>

double ln(double x, double absError, unsigned k)
{
  double sum = 0;
  double member = 0;
  unsigned number = 0;
  do
  {
  //iskluchenie
  //member?
    number++;
  }
  while(number != numberMax || std::abs(member) > absError);
  return sum;
}
