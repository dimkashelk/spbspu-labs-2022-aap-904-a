#include "elements.h"

size_t potapova::findNegativeAfterMax(const int* array, size_t size)
{

}

size_t potapova::findRepeatingPositiveNumbers(const int* array, size_t size)
{
  size_t count_pairs = 0
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 1; j < size; j++) {
      if (a[i] > 0 && a[j] > 0 && a[i] < a[j] && a[i] == a[j]) {
        count_pairs++;
      }
    }
    if (count_pairs > 0) {
      std::cout << "Yes" << "\n";
    }
  }
}
