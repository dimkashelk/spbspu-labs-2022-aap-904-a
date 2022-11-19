#include "stringbuilder.h"
#include <iostream>
char *remove_extra_spaces(char *destination, const char *source, int *res_size)
{
  StringBuilder stringBuilder;
  int j = 0;
  while (source[j] == ' ')
  {
    j++;
  }
  int i = 0;
  while (source[j])
  {
    if (source[j] == ' ')
    {
      while (source[j] == ' ')
      {
        j++;
      }
      stringBuilder.add_char(' ');
      j--;
    }
    else
    {
      stringBuilder.add_char(source[j]);
    }
    i++;
    j++;
  }
  int new_size = stringBuilder.get_size();
  while (stringBuilder.get_char(new_size - 1) == ' ')
  {
    stringBuilder.remove_char(new_size - 1);
    new_size--;
  }
  *res_size = stringBuilder.get_size();
  char *dop = stringBuilder.get_string();
  for (int k = 0; k < stringBuilder.get_size(); k++)
  {
    destination[k] = dop[k];
  }
  delete[] dop;
  return destination;
}
char *get_other_symbols(char *destination, const char *source, int *res_size)
{
  int alphabet[26];
  for (int i = 0; i < 26; i++)
  {
    alphabet[i] = 0;
  }
  for (int i = 0; source[i]; i++)
  {
    if (source[i] >= 'a' && source[i] <= 'z')
    {
      alphabet[static_cast<int>(source[i]) - static_cast<int>('a')]++;
    }
    else if (source[i] >= 'A' && source[i] <= 'Z')
    {
      alphabet[static_cast<int>(source[i]) - static_cast<int>('A')]++;
    }
  }
  int j = 0;
  StringBuilder stringBuilder;
  for (int i = 0; i < 26; i++)
  {
    if (!alphabet[i])
    {
      stringBuilder.add_char(static_cast<char>(static_cast<int>('a') + i));
      j++;
    }
  }
  size_t new_size = stringBuilder.get_size();
  char *dop = stringBuilder.get_string();
  for (int i = 0; i < new_size; i++)
  {
    destination[i] = dop[i];
  }
  delete[] dop;
  *res_size = stringBuilder.get_size();
  return destination;
}
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
  int size1;
  remove_extra_spaces(res1, str, &size1);
  for (int i = 0; i < size1; i++)
  {
    std::cout << res1[i];
  }
  std::cout << '\n';
  delete[] res1;
  char *res2 = new char[26];
  int size2;
  get_other_symbols(res2, str, &size2);
  for (int i = 0; i < 26; i++)
  {
    std::cout << res2[i];
  }
  delete[] res2;
  return 0;
}
