#include "isRepeatingElements.h"
#include "readString.h"
#include "deleteSpaces.h"
#include <iostream>
int main()
{
  char *cstring = nullptr;
  size_t size = 0;
  try
  {
    cstring = readString(std::cin, size);
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  if (cstring[0] == '\n')
  {
    delete[] cstring;
    return 1;
  }
  try
  {
    std::cout << std::boolalpha << isRepeatingElements(cstring) << "\n";
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << "\n";
    delete[] cstring;
    return 1;
  }
  try
  {
    char *strwithoutspaces = new char[size];
    deleteSpaces(strwithoutspaces, cstring);
    std::cout << strwithoutspaces;
    delete[] strwithoutspaces;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete[] cstring;
    return 2;
  }
  delete[] cstring;
}
