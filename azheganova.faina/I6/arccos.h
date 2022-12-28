#ifndef ARCCOS_H
#define ARCCOS_H

double countArccos(double x, double absError, unsigned maxnumber);

class findMemberOfRow
{
  public:
    explicit findMemberOfRow(double x);
    double operator()();
  private:
    double x;
    unsigned numberinnumerator;
    unsigned firstnumber;
    unsigned numberindeminator;
    unsigned secondnumber;
    unsigned thirdnumber;
    unsigned auxiliarynumber;
    unsigned countofnumbers;
};
#endif
