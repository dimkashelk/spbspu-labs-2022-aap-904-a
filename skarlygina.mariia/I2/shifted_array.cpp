#include <iostream>
#include "shifted_array.h"
void makeShiftedArray (const int* array, const size_t N)
{
  if (array && N)
  {
    int* array_flag = new int[N];
    const int first = array[N-1];
    std::cout << " " << first << " ";
    for (size_t i = 1; i < N; i++)
    {
      array_flag[i] = array[i - 1];
      std::cout << array_flag[i] << " ";
    }
    delete[] array_flag;
  }
}
