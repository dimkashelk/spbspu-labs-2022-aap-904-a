#ifndef CALCARCTG_H
#define CALCARCTG_H

double calcArcTg(double x, double absError, unsigned numberMax);

class MemberOfRow
{
public:
  explicit MemberOfRow(double x);
  double operator()();

private:
  double x;
  unsigned ittnum;
  unsigned sign;
};

#endif
