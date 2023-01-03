#include <iostream>
#include <exception>
#include <input_string.hpp>
#include "remove_extra_spaces.h"
#include "delete_identical_chars.h"

int main()
{
  size_t capacity = 10;
  char *cstring_1 = new char[capacity];
  cstring_1[0] = '\0';
  try
  {
    cstring_1 = inputString(cstring_1, capacity);
    if (cstring_1[0] == '\0')
    {
      std::cout << "empty string";
      delete[] cstring_1;
      return 1;
    }
    cstring_1[capacity - 1] = '\0';
  }
  catch (const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring_1;
    return 1;
  }
  char *destination = new char[capacity];
  destination[0] = '\0';
  try
  {
    destination = removeExtraSpaces(destination, cstring_1);
    std::cout << destination << "\n";
    delete[] destination;
  }
  catch (const std::exception &e)
  {
    std::cout << e.what();
    delete[] destination;
    delete[] cstring_1;
    return 1;
  }
  size_t capacity_2 = 10;
  char *cstring_2 = new char[capacity_2];
  cstring_2[0] = '\0';
  try
  {
    cstring_2 = inputString(cstring_2, capacity_2);
    if (capacity_2 == 0)
    {
      cstring_2[capacity_2] = '\0';
    }
    else
    {
      cstring_2[capacity_2 - 1] = '\0';
    }
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
    delete[] cstring_1;
    delete[] cstring_2;
    delete[] destination;
    return 1;
  }

  char *destination_2 = new char[capacity];
  destination_2[0] = '\0';
  try
  {
    destination_2 = deleteIdenticalChars(destination_2, cstring_1, cstring_2);
    std::cout << destination_2 << "\n";
    delete[] cstring_1;
    delete[] cstring_2;
    delete[] destination_2;
  }
  catch (const std::exception& e)
  {
    delete[] cstring_1;
    delete[] cstring_2;
    delete[] destination_2;
    return 1;
  }

  return 0;
}
