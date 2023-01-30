#include "TakeSimilarLettersInOrder.h"
#include <algorithm>
#include <cctype>

char * lettersInOrder (char *result2, const char *source1, const char *source2)
{
  size_t num = 0;
  for (auto i = source1; *i != '\0'; i++) {
    bool existsInBoth = false;
    for (auto j = source2; *j != '\0'; j++) {
      if (std::isalpha(*i) && std::isalpha(*j) &&
        std::tolower(*i) == std::tolower(*j)) {
        existsInBoth = true;
      }
    }

    if (existsInBoth) {
      bool alreadyExists = false;
      for (auto k = result2; k != result2 + 26; k++) {
        if (*k == *i) {
          alreadyExists = true;
          break;
        }
      }
      if (!alreadyExists) {
        result2[num++] = *i;
      }
    }
  }

  for (size_t i = 0; i < num - 1; i++) {
    for (size_t j = 0; j < num - i - 1; j++) {
      if (result2[j] > result2[j + 1]) {
        std::swap(result2[j], result2[j + 1]);
      }
    }
  }
  return result2;
}
