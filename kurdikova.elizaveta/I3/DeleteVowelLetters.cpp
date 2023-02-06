#include "DeleteVowelLetters.h"
#include <cstddef>

char *deleteVowels (char *result1, const char *source)
{
  size_t num = 0;
  char vowelLetters[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
  for (size_t i = 0; source[i] != '\0'; i++) {
    bool isVowel = false;
    for (size_t j = 0; j < 6 ; j++) {
      if (source[i] == vowelLetters[j]) {
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
