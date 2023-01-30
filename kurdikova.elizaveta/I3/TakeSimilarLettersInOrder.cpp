#include "TakeSimilarLettersInOrder.h"
#include <algorithm>
#include <cctype>

char * lettersInOrder (char *result2, const char *source1, const char *source2)
{
  size_t num = 0;
  for (size_t i = 0; source1[i] != '\0'; i++) {
    bool existsInBoth = false;
    for (size_t j = 0; source2[j] != '\0'; j++) {
      if (std::isalpha(source1[i]) && std::isalpha(source2[j]) &&
        std::tolower(source1[i]) == std::tolower(source2[j])) {
        existsInBoth = true;
      }
    }
    if (existsInBoth) {
      bool alreadyExists = false;
      for (size_t k = 0; result2[k] != '\0'; k++) {
        if (result2[k] == source1[i]) {
          alreadyExists = true;
          break;
        }
      }
      if (!alreadyExists) {
        result2[num++] = source1[i];
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
