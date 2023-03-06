#include "createStringFromInput.h"
#include <istream>
#include <cstddef>
#include <stdexcept>
#include "makeStringExtention.h"

char* createStringFromInput(std::istream& input, char* string, size_t size, size_t capacity)
{
  input >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      size_t new_capacity = capacity + 20;
      char* new_str = makeStringExtention(string, capacity, size, new_capacity);
      delete[] string;
      string = new_str;
      new_str = nullptr;
      capacity = new_capacity;
    }
    input >> string[size];
  } while (input && string[size++] != '\n');

  return string;
}
