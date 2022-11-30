#include "GetUniqueSymbols.hpp"
#include <cstddef>
#include <stdexcept>
#include <limits>
#include "ResizeCstring.hpp"

char *get_unique_symbols(char *arr_unique, size_t size_unique, size_t capacity_unique, const char *cstring_one,
                         size_t size_one, const char *cstring_two, size_t size_two)
{
  const size_t max_size_t = std::numeric_limits<size_t>::max();

  bool is_common = false;

  for (size_t i = 0; i < size_one - 1; i++)
  {
    for (size_t j = 0; j < size_two - 1; j++)
    {
      if (cstring_one[i] == cstring_two[j])
      {
        is_common = true;
      }
      if (j == max_size_t)
      {
        throw std::runtime_error("Overflow!");
      }
    }
    if (!is_common)
    {
      try
      {
        arr_unique = check_and_resize(arr_unique, size_unique, capacity_unique);
      }
      catch (const std::runtime_error &e)
      {
        throw std::runtime_error(e.what());
      }
      arr_unique[size_unique] = cstring_one[i];

      if (size_unique == max_size_t)
      {
        throw std::runtime_error("Overflow!");
      }
      
      size_unique++;
    }

    is_common = false;

    if (i == max_size_t)
    {
      throw std::runtime_error("Overflow!");
    }
  }

  for (size_t i = 0; i < size_two - 1; i++)
  {
    for (size_t j = 0; j < size_one - 1; j++)
    {
      if (cstring_two[i] == cstring_one[j])
      {
        is_common = true;
      }
      if (j == max_size_t)
      {
        throw std::runtime_error("Overflow!");
      }
    }
    if (!is_common)
    {
      try
      {
        arr_unique = check_and_resize(arr_unique, size_unique, capacity_unique);
      }
      catch (const std::runtime_error &e)
      {
        throw std::runtime_error(e.what());
      }
      arr_unique[size_unique] = cstring_two[i];

      if (size_unique == max_size_t)
      {
        throw std::runtime_error("Overflow!");
      }

      size_unique++;
    }

    is_common = false;

    if (i == max_size_t)
    {
      throw std::runtime_error("Overflow!");
    }
  }
  arr_unique[size_unique] = '\0';

  return arr_unique;
}