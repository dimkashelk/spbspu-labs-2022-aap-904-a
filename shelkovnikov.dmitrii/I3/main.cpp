#include <iostream>
#include "stringbuilder.h"
#include "removeextraspaces.h"
#include "getothersymbols.h"
int main()
{
  StringBuilder stringBuilder;
  char dop = 'a';
  std::cin >> std::noskipws;
  do
  {
    std::cin >> dop;
    if (!std::cin)
    {
      std::cout << "Error while input\n";
      return 1;
    }
    try
    {
      stringBuilder.add_char(dop);
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what();
      return 2;
    }
  }
  while (std::cin && stringBuilder.get_char(stringBuilder.get_size() - 1) != '\n');
  stringBuilder.remove_char(stringBuilder.get_size() - 1);
  try
  {
    stringBuilder.add_char('\0');
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  char *str = stringBuilder.get_string();
  size_t size = stringBuilder.get_size();
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
  remove_extra_spaces(res1, str, &size1);
  for (size_t i = 0; res1[i]; i++)
  {
    std::cout << res1[i];
  }
  std::cout << '\n';
  delete[] res1;
  try
  {
    char *res2 = new char[26];
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    return 2;
  }
  size_t size2 = 0;
  get_other_symbols(res2, str, &size2);
  for (size_t i = 0; res2[i]; i++)
  {
    std::cout << res2[i];
  }
  delete[] res2;
  return 0;
}
