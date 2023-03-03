#include "duplicateRows.h"
#include <unordered_set>
#include <algorithm>
size_t countDuplicateRows(const int* arr, const size_t m, const size_t n)
{
  size_t count = 0;
  std::unordered_set< int > elements;
  for (size_t i = 0; i < m; i++)
  {
    elements.clear();
    for (size_t j = 0; j < n; j++)
    {
      elements.insert(arr[i * m + j]);
    }
    if (elements.size() == n)
    {
      count++;
    }
  }
  return count;
}
