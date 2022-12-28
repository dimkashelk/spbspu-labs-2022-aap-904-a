#include "arccos.h"
#include <iomanip>
#include <stdexcept>

double countArccos(double x, double absError, unsigned maxnumber)
{
  findMemberOfRow findMemberOfRow(x);
  double res = 0.0;
  double firstmember = 1.57;
  double member = 0;
  unsigned count = 0;
  while (member > absError && count < maxnumber)
  {
    member = findMemberOfRow();
    count++;
    res += member;
  }
  return res;
}

findMemberOfRow::findMemberOfRow(double x):
  x(x * x * x),
  numberinnumerator(1),
  firstnumber(3),
  numberindeminator(1),
  secondnumber(3),
  thirdnumber(1),
  auxiliarynumber(1),
  countofnumbers(0)
{
  if (x < -1 || x > 1)
  {
    throw std::invalid_argument("error");
  }
}

double findMemberOfRow::operator()()
{
  if (countofnumbers == 0)
  {
    return 1,57;
  }
  if (countofnumbers == 1)
  {
    return -x;
  }
  if (countofnumbers == 2)
  {
    return (x * x * x)/6;
  }
  if (countofnumbers > 2)
  {
    x *= x * x;
    numberinnumerator = numberinnumerator * firstnumber * x;
    firstnumber = firstnumber * (firstnumber + 2);
    thirdnumber = (secondnumber + 1) * (secondnumber + 2) ;
    numberindeminator = (numberindeminator * 2 * thirdnumber) / auxiliarynumber;
    secondnumber += 2;
    auxiliarynumber = 2 * (secondnumber + 2);
    return numberinnumerator / numberindeminator;
  }
  countofnumbers++;
}
