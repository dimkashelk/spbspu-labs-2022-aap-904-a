#include <iostream>
#include "StringOperations.h"

int main()
{
  size_t size = 0;
  char* src = new char[1];
  try {
    src = inputString(std::cin, size);
  }
  catch (const std::bad_alloc & err) {
    delete[] src;
    std::cerr << "Error: " << err.what();
    return 1;
  }
  if (src[0] == '\0') {
    delete[] src;
    std::cerr << "Error: string too short";
    return 2;
  }

  //Task11
  char* dest = new char[size];
  switchCase(src, dest);

  std::cout << "string with switched case: " << dest << '\n';
  delete[] dest;

  //Task 19
  dest = new char[4];
  threeMostCommon(src, dest);
  std::cout << "Most common characters: " << dest;

  delete[] dest;
  delete[] src;
}
