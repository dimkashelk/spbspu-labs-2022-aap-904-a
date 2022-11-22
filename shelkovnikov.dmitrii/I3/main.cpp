#include <iostream>
#include "removeextraspaces.h"
#include "getothersymbols.h"
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
        std::cout << "Too long string";
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
        char * newstr = new char[capacity];
        for (auto i = str, j = newstr; i != str + size; ++i, ++j)
        {
          *j = *i;
        }
        delete [] str;
        str = newstr;
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
  str[size - 1] = '\0';
  try
  {
    char *res1 = new char[size];
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    return 2;
  }
  size_t size1 = 0;
  remove_extra_spaces(res1, str, size);
  std::cout << res1 << '\n';
  delete[] res1;
  try
  {
    char *res2 = new char[27];
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    return 2;
  }
  get_other_symbols(res2, str, size);
  std::cout << res2 << '\n';
  delete[] res2;
  return 0;
}
