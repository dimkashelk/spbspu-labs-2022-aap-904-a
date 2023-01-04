#include <iostream>
#include <cstddef>
#include <input_string.h>
#include "expression.h"

int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  cstring[0] = '\0';
  try
  {
    std::pair< size_t, char * > inputString(std::istream &);
    if (cstring[0] == '\0')
    {
      std::cout << "empty string";
      delete[] cstring;
      return 1;
    }
    cstring[capacity - 1] = '\0';
  }
  catch (const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring;
    return 1;
  }
  std::cout << std::boolalpha << isExpression(cstring) << '\n';
  delete [] cstring;
}
