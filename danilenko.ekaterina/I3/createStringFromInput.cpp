#include "createStringFromInput.h"
#include "makeStringExtention.h"
#include <iostream>
#include <cstring>
#include <cstddef>
#include <stdexcept>

char* createStringFromInput(std::istream& input, size_t size, size_t capacity)
{
  char* source1 = nullptr;
  try
  {
    source1 = new char[capacity];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error allocating memory: " << e.what() << '\n';
    delete[] source1;
    return 0;
  }

  input >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      try
      {
        size_t new_cap = capacity + 20;
        char* new_str = makeStringExtention(source1, capacity, size, new_cap);
        delete[] source1;
        source1 = new_str;
        new_str = nullptr;
        capacity = new_cap;
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Error" << e.what() << '\n';
        delete[] source1;
        return 0;
      }
    }
    input >> source1[size];
  }
  while (input && source1[size] != '\0' && source1[size++] != '\n');

  if (size <= 1)
  {
    std::cerr << "Empty string" << '\n';
    delete[] source1;
    return nullptr;
  }
  source1[size - 1] = '\0';
  return source1;
}
