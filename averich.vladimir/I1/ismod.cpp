#include "ismod.hpp"
int isMod(int prevalue, int value)
{
  if (value % prevalue == 0)
  {
   return true;
  }
  else
  {
   return false;
  }
}
