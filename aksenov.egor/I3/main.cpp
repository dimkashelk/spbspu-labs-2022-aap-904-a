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
    cstring = readString(std::cin);
  }
  catch (...)
  {
    std::cerr << "Error\n";
    return 2;
  }
  try
  {
    std::cout << std::boolalpha << isRepeatingElements(cstring) << "\n";
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << "\n";
  }
  char *strwithoutspaces = new char[size];
  strwithoutspaces = deleteSpaces(strwithoutspaces, cstring);
  std::cout << strwithoutspaces;
  delete[] cstring;
  delete[] strwithoutspaces;
}
