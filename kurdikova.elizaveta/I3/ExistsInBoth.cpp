#include "ExistsInBoth.h"
#include <cctype>

bool isExistsInBoth (char letter1, char letter2)
{
  if (std::isalpha(letter1) && std::isalpha(letter2)) {
    if (std::tolower(letter1) == std::tolower(letter2)) {
      return true;
    }
  }
  return false;
}
