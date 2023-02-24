#include <iostream>
#include <cstddef>
#include <algorithm>
#include "removeDuplicateSpaces.h"
#include "removeDigits.h"

int main()
{
  constexpr size_t initialCapacity = 10;
  constexpr size_t capacityIncrement = 20;
  size_t capacity = initialCapacity;
  char* cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  char inputCharacter;
  while (std::cin >> inputCharacter)
  {
    if (size == capacity - 1)
    {
      char* newString = nullptr;
      try
      {
        newString = new char[capacity + capacityIncrement];
        std::copy(cstring, cstring + capacity, newString);
        delete [] cstring;
        cstring = newString;
        capacity += capacityIncrement;
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << e.what() << '\n';
        delete [] cstring;
        return 1;
      }
    }
    cstring[size++] = inputCharacter;
    if (inputCharacter == '\n')
    {
      break;
    }
  }
  if (size == 0)
  {
    std::cerr << "Empty string\n";
    delete [] cstring;
    return 1;
  }
  cstring[size - 1] = '\0';
  char* newString = nullptr;
  newString = removeDuplicateSpaces2(cstring);
  removeDigits(newString, newString);
  std::cout << newString << '\n';
  if (newString != nullptr) {
    delete [] newString;
  }
  if (cstring != nullptr) {
    delete [] cstring;
  }
  return 0;
}
