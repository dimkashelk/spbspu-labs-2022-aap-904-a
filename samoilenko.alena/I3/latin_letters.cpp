#include <cctype>
char* printNewLatinLetters(char* destination, const char* source)
{
  unsigned int ascii[26] = {};
  int i = 0;
  while (source[i] != '\0')
  {
    if (isalpha(source[i]))
    {
      ascii[int(tolower(source[i])) - 97]++;
    }
    i++;
  }
  int j = 0;
  for (i = 0; i < 26; i++)
  {
    if (ascii[i] == 0)
    {
      destination[j] = char(i + 97);
      j++;
    }
  }
  destination[j] = '\0';
  return destination;
}
