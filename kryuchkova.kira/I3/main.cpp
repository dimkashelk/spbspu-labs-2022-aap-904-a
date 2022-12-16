#include <iostream>
#include <exception>
#include "remove_extra_spaces.h"
#include "delete_identical_chars.h"
#include "input_string.h"

int main()
{
  size_t capacity = 10;
  char *cstring_1 = new char[capacity];
  cstring_1[0] = '\n';
  try
  {
    cstring_1 = input_string(cstring_1);
  }
  catch(std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring_1;
    return 1;
  }

  char *destination = new char[capacity];
  destination[0] = '\n';
  std::cout << remove_extra_spaces(destination, cstring_1) << "\n";
  delete[] destination;

  char *cstring_2 = new char[capacity];
  cstring_2[0] = '\n';
  try
  {
    cstring_2 = input_string(cstring_2);
  }
  catch(std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring_2;
    return 1;
  }

  char *destination_2 = new char[capacity];
  destination_2[0] = '\n';
  std::cout << delete_identical_chars(destination_2, cstring_1, cstring_2) << "\n";
  delete[] cstring_1;
  delete[] cstring_2;
  delete[] destination_2;
}
