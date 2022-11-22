#include "getothersymbols.h"
#include "stringbuilder.h"
char *get_other_symbols(char *destination, char *source, size_t source_size)
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
  char *str = new char[27];
  for (size_t i = 0; i < 26; i++)
  {
    if (!alphabet[i])
    {
      str[j] = static_cast<char>(static_cast< size_t >('a') + i));
      j++;
    }
  }
  str[j] = '\0';
  for (size_t i = 0; i < j; i++)
  {
    destination[i] = str[i];
  }
  delete[] str;
  return destination;
}
