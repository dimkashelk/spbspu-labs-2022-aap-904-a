#include "createStringFromInput.h"
#include <istream>
#include <cstring>
#include <cstddef>
#include <stdexcept>

char* createStringFromInput(std::istream& input)
{
  size_t size1 = 0;
  size_t capacity = 10;
  char* source1 = nullptr;
  source1 = new char[capacity];

  input >> std::noskipws;

  do
  {
    if (size1 == capacity)
    {
      try
      {
        char* new_string = new char[capacity + 20];
        for (auto i = source1, j = new_string; i != source1 + size1; i++, j++)
        {
          *j = *i;
        }
        delete[] source1;
        source1 = new_string;
        capacity += 20;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] source1;
        return 0;
      }
    }
    input >> source1[size1];
  }
  while (input && source1[size1++] != '\n');

  if (size1 <= 1)
  {
    throw std::logic_error("Empty string");
    delete[] source1;
    return 0;
  }
  source1[size1 - 1] = '\0';

  return source1;
}
