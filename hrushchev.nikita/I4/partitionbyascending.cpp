#include "partitionbyascending.hpp"
#include <utility>

int* partitionByAscending(int* begin, int* end)
{
  for (int* i = begin; i != end - 1; ++i)
  {
    int* min = i;
    for (int* j = i + 1; j != end; ++j)
    {
      if (*j < *min)
      {
        min_ptr = j;
      }
    }
    std::swap(*i, *min_ptr);
  }
  return begin;
}
