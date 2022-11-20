#include "removeextraspaces.h"
#include "stringbuilder.h"
char *remove_extra_spaces(char *destination, const char *source, size_t *res_size)
{
  StringBuilder stringBuilder;
  size_t j = 0;
  while (source[j] == ' ')
  {
    j++;
  }
  size_t i = 0;
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
  size_t new_size = stringBuilder.get_size();
  while (stringBuilder.get_char(new_size - 1) == ' ')
  {
    stringBuilder.remove_char(new_size - 1);
    new_size--;
  }
  stringBuilder.add_char('\0');
  *res_size = stringBuilder.get_size();
  char *dop = stringBuilder.get_string();
  for (size_t k = 0; dop[k]; k++)
  {
    destination[k] = dop[k];
  }
  delete[] dop;
  return destination;
}
