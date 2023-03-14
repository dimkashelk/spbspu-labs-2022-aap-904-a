#include "readArray.h"
#include <stdexcept>

int* readArrayFromFile(int* matrix, size_t size, std::ifstream& input)
{
  for (size_t i = 0; i < size; i++)
  {
    input >> matrix[i];
    if (!input)
    {
      throw std::logic_error("Incorrect args");
    }
  }
  return matrix;
}
