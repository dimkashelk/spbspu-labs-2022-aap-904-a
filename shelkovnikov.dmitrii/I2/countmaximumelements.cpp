#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTMAXIMUMELEMENTS_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTMAXIMUMELEMENTS_H
#include <limits>
#include <stdexcept>
int get_maximum(int *arr, size_t size)
{
  int maximum = std::numeric_limits< int >::min();
  for (size_t i = 0; i < size; i++)
  {
    if (maximum < arr[i])
    {
      maximum = arr[i];
    }
  }
  return maximum;
}
unsigned int count_maximum_elements(int *arr, size_t size)
{
  unsigned int count = 0;
  int maximum = get_maximum(arr, size);
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  for (size_t i = 0; i < size; i++)
  {
    if (maximum == arr[i])
    {
      if (count == max_int)
      {
        throw std::overflow_error("Too much numbers....");
      }
      count++;
    }
  }
  return count;
}
#endif
