#include <iostream>
#include <stdexcept>
#include "DelNumbers.h"
#include "RepLetters.h"
#include "FormingCstring.h"

int main()
{
  size_t size = 0;
  char* cstring = nullptr;
  try
  {
    cstring = formingCstring(size, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
    delete[] cstring;
    return 2;
  }

  char* destination1 = nullptr;

  destination1 = deleteNumbers(cstring, destination1);
  std::cout << destination1 << "\n";

  char* destination2 = nullptr;

  destination2 = replacingLetters(cstring, destination2);
  std::cout << destination2 << "\n";
  delete[] cstring;
  delete[] destination1;
  delete[] destination2;
}
