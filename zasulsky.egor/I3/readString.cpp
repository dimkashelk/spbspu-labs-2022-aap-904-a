#include "readString.hpp"
#include <iostream>
#include <cstddef>
#include "extendString.hpp"

char* zasulsky::readString(std::istream& in)
{
  size_t capacity = 10;
  size_t size = 0;
  char* cstring = new char[capacity];

  in >> std::noskipws;
  do {
    if (size == capacity - 1) {
      try {
        cstring[size] = '\0';
        char* newstr = extendString(cstring, capacity, capacity + 20);
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
      } catch (...) {
        delete [] cstring;
        throw;
      }
    }
    in >> cstring[size];
  } while (in && cstring[size++] != '\n');
  cstring[size - 1] = '\0';
  return cstring;
}
