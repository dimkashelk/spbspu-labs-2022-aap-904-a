#include "getothersymbols.h"
#include "stringbuilder.h"
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
