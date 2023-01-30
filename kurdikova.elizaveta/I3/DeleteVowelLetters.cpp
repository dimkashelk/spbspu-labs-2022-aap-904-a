#include "DeleteVowelLetters.h"
#include <cstddef>

char * deleteVowels (char *result1, const char *source)
{
  int num = 0;
  char vowelLetters[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
  for (size_t i = 0; source[i] != '\0'; i++) {
    bool isVowel = false;
    for (char j : vowelLetters) {
      if (source[i] == j) {
        isVowel = true;
        break;
      }
    }
    if (!isVowel) {
      result1[num++] = source[i];
    }
  }
  return result1;
}
