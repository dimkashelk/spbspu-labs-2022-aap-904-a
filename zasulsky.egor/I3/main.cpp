#include <iostream>
#include <cstddef>
#include "countUniqueLatin.hpp"
#include "replaceSymbol.hpp"
#include "readString.hpp"
#include "getStringSize.hpp"

int main()
{
  char* cstring = zasulsky::readString(std::cin);
  size_t size = zasulsky::getStringSize(cstring);
  if (size == 0) {
    std::cout << "Empty string\n";
    return 1;
  }

  char* newstr = nullptr;
  try {
    newstr = new char[size + 1];
  } catch (...) {
    delete [] cstring;
    delete [] newstr;
    return 1;
  }
  std::cout << zasulsky::replaceSymbol(newstr, cstring, 'e', 'a') << '\n';
  delete [] newstr;

  std::cout << zasulsky::countUniqueLatin(cstring) << '\n';

  delete [] cstring;
}
