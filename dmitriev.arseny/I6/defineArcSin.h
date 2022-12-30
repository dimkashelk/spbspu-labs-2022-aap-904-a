#ifndef DEFINEARCSIN
#define DEFINEARCSIN

double defineArcSin(double x, double absError, unsigned numberMax);

class MemberOfRow
{
public:
  MemberOfRow(double x);
  double operator()();

private:
  double x;
  double powX;
  unsigned even;
  unsigned odd;
  unsigned factorialEven;
  unsigned factorialOdd;

};

#endif
