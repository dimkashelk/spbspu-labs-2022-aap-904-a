#include "countcolumnsequalsumelement.hpp"
#include <cstddef>
#include <algorithm>

size_t countColumnsEqualSumElement(const int* array, const size_t rows, const size_t columns)
{
  if (columns == 1)
  {
    return 0;
  }

  int* array_sum = nullptr;
  try
  {
    int* array_sum = new int[columns];
    size_t count = 0;
    int current_sum = 0;

    for (size_t i = 0; i < columns; i++)
    {
      for (size_t j = 0; j < rows; j++)
      { 
        current_sum += array[i + rows * j];
      }
      array_sum[i] = current_sum;
      current_sum = 0;
    }

    std::sort(array_sum, array_sum + columns);
    int current_count = 1;
    for (size_t i = 0; i < columns - 1; i++)
    {
      if (array_sum[i] == array_sum[i + 1])
      {
        current_count++;
      }
      else
      {
        if (current_count> 1)
        {
          count += current_count;
        }
        current_count = 1;
      }
    }
    delete[] array_sum;
    return count;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] array_sum;
    throw e;
  }
}

