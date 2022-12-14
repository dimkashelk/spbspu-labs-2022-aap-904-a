#include "checkcharacterssimilarity.h"

bool checkCharactersSimilarity(const char *source) {
  size_t i = 1;
  while (source[i] != '\0') {
    if (source[i] == source[i - 1]) {
      return true;
    }
    i++;
  }
  return false;
}
