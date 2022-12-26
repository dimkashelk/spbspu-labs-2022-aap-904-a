#include <iostream>
#include "printtable.h"
#include "sinh.h"
#include "comparedoubles.h"
int main()
{
  double test = 0.8;
  printTable(std::cout, -1, 1, 0.1, test, 1e-4, 10);
}
