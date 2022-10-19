#include "compute.h"

int turkin::max(int a, int b)
{
  return (a > b) ? a : b;
}

int turkin::condition(int current)
{
  return (current != 0) ? 1 : 0;
}

int turkin::condition(int last, int current, int amount)
{
  return (current == last && current != 0) ? ++amount : 1;
}

