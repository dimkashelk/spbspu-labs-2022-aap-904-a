#include <iostream>
#include "remove_extra_spaces.h"
#include "delete_identical_chars.h"
#include "input_string.h"
#include <exception>

int main()
{
  char *cstring_1 = nullptr;
  try
  {
    cstring_1 = input_string(cstring_1);
  }
  catch(...)
  {
    return 1;
  }

  char *destination = nullptr;
  std::cout << "First string without extra spaces: '" << remove_extra_spaces(destination, cstring_1) << "'\n";
  delete [] destination;

  char *cstring_2 = nullptr;
  try
  {
    cstring_2 = input_string(cstring_2);
  }
  catch(std::exception &e)
  {
    std::cout << e.what();
    return 1;
  }

  char *destination_2 = nullptr;
  std::cout << "First string without chars in second string: '" << delete_identical_chars(destination_2, cstring_1, cstring_2) << "'\n";
  delete [] destination_2;

  delete [] cstring_1;
  delete [] cstring_2;
}
