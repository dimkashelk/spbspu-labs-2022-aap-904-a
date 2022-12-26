#include <iostream>
#include "finder_same_elements_in_two_strings.h"

void finderSameElementsInTwoStrings(const char *first_string, const char *second_string, size_t size_first_string, size_t size_second_string)
{
  size_t final_size = size_first_string + size_second_string;
  char result_string[final_size];
  size_t cnt = -1;
  for (size_t i = 0; i < size_first_string; ++i)
  {
    for (size_t j = 0; j < size_second_string; ++j)
    {
      if (first_string[i] == second_string[j])
      {
        cnt++;
        result_string[cnt] = first_string[i];
      }
    }
  }

  for (size_t i = 0; i <= final_size; ++i)
  {
    std::cout << result_string[i] << " ";
  }
}
