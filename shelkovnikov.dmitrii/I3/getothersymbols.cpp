#include "getothersymbols.h"
#include "stringbuilder.h"
char *get_other_symbols(char *destination, const char *source, size_t *res_size)
{
  int alphabet[26];
  for (size_t i = 0; i < 26; i++)
  {
    alphabet[i] = 0;
  }
  for (size_t i = 0; source[i]; i++)
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
  size_t j = 0;
  StringBuilder stringBuilder;
  for (size_t i = 0; i < 26; i++)
  {
    if (!alphabet[i])
    {
      stringBuilder.add_char(static_cast<char>(static_cast<int>('a') + i));
      j++;
    }
  }
  stringBuilder.add_char('\0');
  char *dop = stringBuilder.get_string();
  for (size_t i = 0; dop[i]; i++)
  {
    destination[i] = dop[i];
  }
  delete[] dop;
  *res_size = stringBuilder.get_size();
  return destination;
}
