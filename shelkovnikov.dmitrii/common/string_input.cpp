#include "string_input.h"
#include <limits>
#include <stdexcept>
char* string_input(std::istream &in, char* destination, size_t capacity)
{
  in >> std::noskipws;
  constexpr size_t max_size_t = std::numeric_limits< size_t >::max();
  size_t size = 0;
  do
  {
    if (size == capacity)
    {
      if (capacity == max_size_t)
      {
        throw std::runtime_error("Too long string");
      }
      if (max_size_t - 20 <= capacity)
      {
        capacity = max_size_t;
      }
      else
      {
        capacity += 20;
      }
      try
      {
        char *newstr = new char[capacity];
        for (auto i = destination, j = newstr; i != destination + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] destination;
        destination = newstr;
      }
      catch (...)
      {
        delete[] destination;
        throw std::runtime_error("Error while getting new memory");
      }
    }
    in >> destination[size];
  }
  while (in && destination[size++] != '\n');
  if (!in && !size)
  {
    delete[] destination;
    throw std::runtime_error("Error while input");
  }
  destination[size - 1] = '\0';
  return destination;
}
