#include "arccos.h"
#include <iomanip>
#include <stdexcept>

double countArccos(double x, double absError, unsigned maxnumber)
{
  findMemberOfRow findMemberOfRow(x);
  double res = 0.0;
  double member = 1.57 - x;
  unsigned count = 0;
  while (member > absError && count < maxnumber)
  {
    res += member;
    member = findMemberOfRow();
    count++;
  }
  return res;
}

findMemberOfRow::findMemberOfRow(double x):
  x(x),
  numberinnumerator(1),
  firstnumber(1),
  numberindeminator(3),
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
  x *= x * x;
  numberinnumerator = numberinnumerator * firstnumber * x;
  firstnumber = firstnumber * (firstnumber + 2);
  numberindeminator = (numberindeminator * 2 * thirdnumber) / auxiliarynumber;
  thirdnumber = (secondnumber + 1) * (secondnumber + 2);
  secondnumber += 2;
  auxiliarynumber = 2 * (secondnumber + 2);
  return numberinnumerator / numberindeminator;
}
