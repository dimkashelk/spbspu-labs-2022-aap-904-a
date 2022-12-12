#include <iostream>
#include <cstddef>
#include <limits>
#include "recursion.h"
#include "../common/string_input.h"
#include "../common/free_memory.h"
int main()
{
  size_t capacity = 10;
  size_t size = 0;
  constexpr size_t max_size_t = std::numeric_limits< size_t >::max();
  char** strings = new char*[capacity];
  while (!std::cin)
  {
    size_t str_capacity = 10;
    char* str = new char[str_capacity];
    try
    {
      string_input(std::cin, str, str_capacity);
    }
    catch (const std::runtime_error &e)
    {
      std::cout << e.what();
      free_memory(strings, size);
      return 1;
    }
    strings[size++] = str;
    if (size == capacity)
    {
      if (capacity == max_size_t)
        {
          std::cout << "Too much strings";
          free_memory(strings, size);
          return 1;
        }
      if (max_size_t - 20 <= capacity)
        {
          capacity = max_size_t;
        }
      else
        {
          capacity += 20;
        }
      try
        {
          try
          {
            char **new_strings = new char*[capacity];
            for (size_t i = 0; i < size; i++)
            {
              new_strings[i] = strings[i];
            }
            delete[] strings;
            strings = new_strings;
          }
          catch (...)
          {
            std::cout << "Error";
            free_memory(strings, size);
            return 2;
          }
        }
    }
  }
  std::cout << std::boolalpha;
  for (size_t i = 0; i < size; i++)
  {
    std::cout << is_real_number(strings[i]) << '\n';
  }
  free_memory(strings, size);
  return 0;
}
