#ifndef PRINTTABLE_H
#define PRINTTABLE_H
#include <ostream>

void printTableRow(std::ostream& out, double x, double absError, unsigned members);
void printTable(std::ostream& out, double left, double right, size_t members, double absError, double step);

#endif
