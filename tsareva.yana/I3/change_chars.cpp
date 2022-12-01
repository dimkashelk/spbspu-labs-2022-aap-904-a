#include "change_chars.h"
#include <cstddef>
char* change_chars(char* res, char* str)
{
  for (size_t i = 0; str[i]; i++)
  {
    if (str[i] == 'A')
    {
      res[i] = 'a';
    }
    else if (str[i] == 'B')
    {
      res[i] = 'b';
    }
    else if (str[i] == 'C')
    {
      res[i] = 'c';
    }
    else if (str[i] == 'D')
    {
      res[i] = 'd';
    }
    else if (str[i] == 'E')
    {
      res[i] = 'e';
    }
    else if (str[i] == 'F')
    {
      res[i] = 'f';
    }
    else if (str[i] == 'G')
    {
      res[i] = 'g';
    }
    else if (str[i] == 'H')
    {
      res[i] = 'h';
    }
    else if (str[i] == 'I')
    {
      res[i] = 'i';
    }
    else if (str[i] == 'J')
    {
      res[i] = 'j';
    }
    else if (str[i] == 'K')
    {
      res[i] = 'k';
    }
    else if (str[i] == 'L')
    {
      res[i] = 'l';
    }
    else if (str[i] == 'M')
    {
      res[i] = 'm';
    }
    else if (str[i] == 'N')
    {
      res[i] = 'n';
    }
    else if (str[i] == 'O')
    {
      res[i] = 'o';
    }
    else if (str[i] == 'P')
    {
      res[i] = 'p';
    }
    else if (str[i] == 'Q')
    {
      res[i] = 'q';
    }
    else if (str[i] == 'R')
    {
      res[i] = 'r';
    }
    else if (str[i] == 'S')
    {
      res[i] = 's';
    }
    else if (str[i] == 'T')
    {
      res[i] = 't';
    }
    else if (str[i] == 'U')
    {
      res[i] = 'u';
    }
    else if (str[i] == 'V')
    {
      res[i] = 'v';
    }
    else if (str[i] == 'W')
    {
      res[i] = 'w';
    }
    else if (str[i] == 'X')
    {
      res[i] = 'x';
    }
    else if (str[i] == 'Y')
    {
      res[i] = 'y';
    }
    else if (str[i] == 'Z')
    {
      res[i] = 'z';
    }
    else
    {
      res[i] = str[i];
    }
  }
  return res;
}
