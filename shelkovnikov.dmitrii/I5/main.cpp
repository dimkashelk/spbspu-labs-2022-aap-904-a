#include <iostream>
#include "recursion.h"
int main()
{
  size_t capacity = 10;
  char * str = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  constexpr size_t max_size_t = std::numeric_limits< size_t >::max();
  do
  {
    if (size == capacity)
    {
      if (capacity == max_size_t)
      {
        std::cout << "Too long number";
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
        char * new_number = new char[capacity];
        for (auto i = str, j = new_number; i != str + size; ++i, ++j)
        {
          *j = *i;
        }
        delete [] str;
        str = new_number;
      }
      catch (...)
      {
        delete [] str;
        return 1;
      }
    }
    std::cin >> str[size];
  }
  while (std::cin && str[size++] != '\n');
  if (!std::cin && !size)
  {
    std::cout << "Error while input";
    delete[] str;
    return 2;
  }
  str[size - 1] = '\0';
  std::cout << is_real_number(str, size - 1);
  return 0;
}
