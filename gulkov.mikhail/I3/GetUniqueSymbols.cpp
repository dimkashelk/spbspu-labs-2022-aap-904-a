#include "GetUniqueSymbols.hpp"
#include <cstddef>
#include <stdexcept>
#include <limits>
#include "ResizeCstring.hpp"

char *get_unique_symbols
  (char *arr_unique, size_t size_unique, size_t capacity_unique, const char *cstring_one,
   const char *cstring_two)
{
  const size_t max_size_t = std::numeric_limits< size_t >::max();
  const unsigned int max_unsigned_int = std::numeric_limits< unsigned int >::max();

  bool is_common = false;

  for (unsigned int i = 0; cstring_one[i] != '\0'; i++)
  {
    for (unsigned int j = 0; cstring_two[j] != '\0'; j++)
    {
      if (cstring_one[i] == cstring_two[j])
      {
        is_common = true;
      }
      if (j == max_unsigned_int)
      {
        throw std::overflow_error("Overflow!");
      }
    }
    if (!is_common)
    {
      arr_unique = check_and_resize(arr_unique, size_unique, capacity_unique);
      arr_unique[size_unique] = cstring_one[i];

      if (size_unique == max_size_t)
      {
        throw std::overflow_error("Overflow!");
      }

      size_unique++;
    }

    is_common = false;
    
    if (i == max_unsigned_int)
    {
      throw std::overflow_error("Overflow!");
    }
  }

  arr_unique[size_unique] = '\0';

  return arr_unique;
}
