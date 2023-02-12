#include "generateRand.h"
#include <iostream>
int *generateRand(size_t size)
{
  int *newar = new int[size];
  std::srand(time(nullptr));
  for (size_t i = 0; i < size; i++)
  {
    newar[i] = std::rand();
  }
  return newar;
}
