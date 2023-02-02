#include "modcount.hpp"
int countIsMod(unsigned int prevalue, unsigned int value)
{
  if (value % prevalue == 0)
  {
   return 1;
  }
  else
  {
   return 0;
  }
}
