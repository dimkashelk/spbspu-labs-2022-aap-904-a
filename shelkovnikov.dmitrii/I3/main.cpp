#include "stringbuilder.h"
#include <iostream>
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
    stringBuilder.add_char(dop);
  }
  while (std::cin && stringBuilder.get_char(stringBuilder.get_size() - 1) != '\n');
  stringBuilder.remove_char(stringBuilder.get_size() - 1);
  stringBuilder.add_char('\0');
  char *str = stringBuilder.get_string();
  size_t size = stringBuilder.get_size();
  char *res1 = new char[size];
  size_t size1;
  remove_extra_spaces(res1, str, &size1);
  for (size_t i = 0; i < res1[i]; i++)
  {
    std::cout << res1[i];
  }
  std::cout << '\n';
  delete[] res1;
  char *res2 = new char[26];
  size_t size2;
  get_other_symbols(res2, str, &size2);
  for (size_t i = 0; res2[i]; i++)
  {
    std::cout << res2[i];
  }
  delete[] res2;
  return 0;
}
