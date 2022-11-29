#include "shifted_array.h"
#include <iostream>

void makeShiftedArray (const int* array, size_t N)
{
  if (array && N)
  {
    int* array_flag = new int[N];
    int first_element = array[N-1];
    std::cout << " " << first_element << " ";
    for (size_t i = 1; i < N; i++)
    {
      array_flag[i] = array[i - 1];
      std::cout << array_flag[i] << " ";
    }
    delete[] array_flag;
  }
}
