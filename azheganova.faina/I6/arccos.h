#ifndef ARCCOS_H
#define ARCCOS_H

double countArccos(double x, double absError, unsigned maxnumber);

struct findMemberOfRow
{
  explicit findMemberOfRow(double x);
  double operator()();
  double x;
  unsigned numberinnumerator;
  unsigned firstnumber;
  unsigned numberindeminator;
  unsigned secondnumber;
  unsigned thirdnumber;
  unsigned auxiliarynumber;
};
#endif
