#include <iostream>
#include "sequence1.h"

void ElementsMoreThanPrev::operator()(int curr)
{
  if (prev > curr) 
  {
     cnt++;
     curr = prev;
  }
}
