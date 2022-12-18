#ifndef PRINTTABLE_H
#define PRINTTABLE_H
#include <cstddef>
#include <iosfwd>

namespace chemodurov
{
  void printTable(std::ostream & out, double left, double right, double step, double error, size_t max_members);
}

#endif
