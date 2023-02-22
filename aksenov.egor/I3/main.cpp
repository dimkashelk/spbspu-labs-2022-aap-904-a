#include "isRepeatingElements.h"
#include "readString.h"
#include "deleteSpaces.h"
#include <iostream>
int main()
{
  char *cstring = nullptr;
  size_t size = 0;
  cstring = readString(std::cin);
  std::cout << std::boolalpha << isRepeatingElements(cstring);
  char *strwithoutspaces = new char[size];
  strwithoutspaces = deleteSpaces(strwithoutspaces, cstring);
  std::cout << strwithoutspaces;
  delete[] cstring;
}
