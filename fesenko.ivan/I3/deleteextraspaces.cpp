#include "deleteextraspaces.h"
#include <cctype>

char *deleteExtraSpaces(char *destination, const char *source)
{
  size_t i = 0, j = 0;
  while (source[i] != '\0') {
    if (!std::isspace(source[i])) {
      destination[j] = source[i];
      j++;
    } else if (j != 0 && destination[j - 1] != ' ') {
      destination[j] = ' ';
      j++;
    }
    i++;
  }
  if (destination[j - 1] == ' ') {
    j--;
  }
  destination[j] = '\0';
  return destination;
}
