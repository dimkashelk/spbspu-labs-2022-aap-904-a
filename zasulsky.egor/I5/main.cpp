#include <cstddef>
#include <iostream>
#include <tuple>
#include "readString.hpp"
#include "isExpression.hpp"

int main()
{
  std::tuple< char*, size_t, size_t > stringData = zasulsky::readString(std::cin);
  char* cstring = std::get< 0 >(stringData);
  std::cout << std::boolalpha << zasulsky::isExpression(cstring) << '\n';
  delete [] cstring;
}
