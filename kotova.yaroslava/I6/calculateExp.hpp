#ifndef CALCULATEEXP_HPP
#define CALCULATEEXP_HPP
#include <iosfwd>
double exp(double x, double absError, unsigned numberMax);
void printRow(std::ostream& out, double x, double absError, unsigned numberMax);
void printTable(std::ostream& out, double left, double right, double step, double absError, unsigned numberMax);
#endif
