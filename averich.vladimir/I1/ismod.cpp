#include "ismod.hpp"
bool isMod(int prevalue, int value)
{
  bool cond = true;
  if (value % prevalue == 0)
  {
   return cond;
  }
  else
  {
   cond = false;
   return cond;
  }
  return cond;
}
