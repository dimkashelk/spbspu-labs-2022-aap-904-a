#include <cstddef>
#include <iostream>
#include <tuple>
#include "readString.hpp"
#include "isExpression.hpp"

int main()
{
  std::tuple< char*, size_t, size_t > stringData = zasulsky::readString(std::cin);
  size_t size = std::get< 1 > (stringData);
  if (size == 1) {
    std::cout << "Empty string\n";
    return 1;
  }
  char* cstring = std::get< 0 >(stringData);
  std::cout << std::boolalpha << zasulsky::isExpression(cstring) << '\n';
  delete [] cstring;
}
