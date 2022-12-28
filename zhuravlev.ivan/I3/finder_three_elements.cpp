#include "finder_three_elements.h"
#include <iostream>

void finderThreeSameElements(const char *str, size_t size)
{
  int cnt_elem = 0;
  int elem[256]{};
  for (int i = 0; i < 256; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      if (static_cast<int> (str[j]) == i)
      {
        cnt_elem++;
      }
    }
    elem[i] = cnt_elem;
    cnt_elem = 0;
  }
  elem[0] = 0;
  elem[32] = 0;
  int max = 0;
  int ind = 0;

  for (int j = 0; j < 3; ++j)
  {
    for (int i = 0; i < 256; ++i)
    {
      if (elem[i] > max)
      {
        max = elem[i];
        ind = i;
      }
    }
    for (int q = 0; q < max; ++q)
    {
      std::cout << static_cast<char> (ind) << " ";
    }
    max = 0;
    elem[ind] = 0;
  }
  std::cout << "/0"
  std::cout << "\n";
}
