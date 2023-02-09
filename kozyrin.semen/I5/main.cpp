#include <iostream>
#include <InputString.h>
#include "IsReal.h"

int main()
  {
    size_t size = 0;
    char* str = nullptr;
    try {
      str = inputString(std::cin, size);
    }
    catch (const std::bad_alloc & err) {
      std::cerr << "Problem with input stream";
      return 1;
    }
    if (size == 1) {
      std::cout << "Empty string";
      delete[] str;
      return 0;
    }
    std::cout << std::boolalpha << isReal(str);
    delete[] str;
  };