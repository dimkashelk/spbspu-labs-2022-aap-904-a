#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <createStringFromInput.h>
#include "isRealNumber.h"

int main()
{
  char* string = nullptr;
  try
  {
    string = createStringFromInput(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << "\n";
    delete[] string;
    return 1;
  }
  if (*string == '\0' || *string == '\n')
  {
    std::cout << "Nothing was entered!" << '\n';
    delete[] string;
    return 1;
  }
  bool result = isRealNumber(string);
  std::cout << std::boolalpha << result << '\n';
  delete[] string;
  return 0;
}
