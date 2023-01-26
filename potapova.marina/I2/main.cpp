#include <iostream>
#include "elements.h"

int main {
  int array[10] = {-1, 5, -5, 5, 3, 2, 5, -27, 4, 1};
  size_t array_size = 10;
  size_t neg_after_max = potapova::findNegativeAfterMax(array, array_size);
  size_t repeat_pos_numb = potapova::findRepeatingPositiveNumbers(array, array_size);
  std::cout << neg_after_max << " " << repeat_pos_numb << "\n";
}
