#include <iostream>

char* remove_extra_spaces(char *destination, const char *source, int size)
{
  int j = 0;
  while (source[j] == ' ')
  {
    j++;
  }
  int i = 0;
  while (j < size)
  {
    if (source[j] == ' ')
    {
      while (source[j] == ' ')
      {
        j++;
      }
      destination[i] = ' ';
      j--;
    }
    else
    {
      destination[i] = source[j];
    }
    i++;
    j++;
  }
  return destination;
}

int main()
{
  return 0;
}
