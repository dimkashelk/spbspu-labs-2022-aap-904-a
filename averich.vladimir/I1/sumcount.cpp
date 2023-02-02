#include "sumcount.hpp"
int countIsSum(unsigned int preprevalue, unsigned int prevalue, unsigned int value)
{
  if (preprevalue + prevalue == value)
  {
   return 1;
  }
  else
  {
   return 0;
  }
}
