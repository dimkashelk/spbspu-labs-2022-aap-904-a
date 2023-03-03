#include "factorial.h"

unsigned factorial(unsigned number)
{
  if (number == 0)
  {
    return 1;
  }
  else
  {
    return number * factorial(number - 1);
  }
}
