#include <iostream>
#include <cstddef>
#include "cString.h"
#include "methods.h"

int main()
{
  const size_t basicCapacity = 10;
  turkin::Array string(basicCapacity);
  std::cin >> std::noskipws;
  do
  {
    if (!string.push(std::cin))
    {
      std::cerr << "out of size\n";
      return 1;
    }
  }
  while (std::cin && string.data[string.size - 1] != '\n');
  if (!std::cin)
  {
    std::cerr << "incorrect input\n";
    return 1;
  }
  if (string.size == 1)
  {
    std::cerr << "null string\n";
    return 1;
  }
  std::cout << turkin::isRepeat(string) << '\t' << turkin::deleteNumbers(string).data << '\n';
  return 0;
}
