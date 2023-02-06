#include "ismod.hpp"
int isMod(int prevalue, int value)
{
  if (value % prevalue == 0)
  {
   return 1;
  }
  else
  {
   return 0;
  }
  return 0;
}
