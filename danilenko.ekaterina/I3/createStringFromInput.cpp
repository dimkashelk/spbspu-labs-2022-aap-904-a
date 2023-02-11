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
    return nullptr;
  }

  input >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      try
      {
        char* previous_string = source1;
        size_t capacity_extention = 20;
        source1 = makeStringExtention(source1, capacity, size, capacity_extention);
        delete previous_string;
        capacity += 20;
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Error" << e.what() << '\n';
        delete[] source1;
        return nullptr;
      }
    }
    input >> source1[size];
  }
  while (input && source1[size++] != '\n');

  if (size <= 1)
  {
    delete[] source1;
    throw std::logic_error("Error. Empty input.");
  }
  else
  {
    source1[size - 1] = '\0';
  }
  return source1;
}
