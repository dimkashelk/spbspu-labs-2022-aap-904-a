#include "issum.hpp"
int isSum(int preprevalue, int prevalue, int value)
{
  if (preprevalue + prevalue == value)
  {
   return true;
  }
  else
  {
   return false;
  }
}
