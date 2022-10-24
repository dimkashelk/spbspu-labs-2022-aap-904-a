#include "compute.h"

int turkin::isSame(int last, int current, int amount)
{
  return (current == last && current != 0) ? ++amount : 0;
}

int turkin::CompareNums::operator()(int last, int current, int amount)
{
  return turkin::isSame(last, current, amount);
}

