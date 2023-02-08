#include "modcount.hpp"
#include "ismod.hpp"
int modCount(int prevalue, int value)
{
  if (isMod(prevalue, value))
  {
   return 1;
  }
  else
  {
   return 0;
  }
  return 0;
}
