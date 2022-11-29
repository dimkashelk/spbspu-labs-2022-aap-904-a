#include "getcountmaxelement.hpp"

int get_count_max_element(int* arr, size_t size)
{
  int max_element = arr[0];
  for (size_t i = 1; i < size; i++)
  {
    {
    if (arr[i] > max_element)
      max_element = arr[i];
    }
  }

  int count_max_element = 0;
  for ( size_t i = 0; i < size; i++)
  {
    if (arr[i] == max_element)
    {
      count_max_element++;
    }
  }
  return count_max_element;
}
