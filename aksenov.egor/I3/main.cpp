#include "isRepeatingElements.h"
#include "readString.h"
#include <iostream>
int main()
{
  char *cstring = nullptr;
  cstring = readString(std::cin);
  std::cout << std::boolalpha << isRepeatingElements(cstring);
}
