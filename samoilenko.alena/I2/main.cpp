#include <iostream>
#include <cstddef>
#include "negative_elements.h"
#include "shifted_array.h"
int main()
{
  const size_t array_shift = 3;
  int array[10] = {6, 9, -11, 4, 1, 26, 73, -38, -45, -21};
  std::cout << countNegativeElementsAfterMax(array, 10) << std::endl;
  size_t size_arr = 10;
  moveTheArray(array, 10, array_shift);
  for(int i = 0; i < size_arr; i++)
  {
    std::cout << array[i] << ' ';
  }
  return 0;
}
