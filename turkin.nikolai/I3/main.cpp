#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "cString.h"
#include "stringTransform.h"

int main()
{
  const size_t basicCapacity = 10;
  char buffer = ' ';
  turkin::String string(basicCapacity);
  std::cin >> std::noskipws;
  do
  {
    std::cin >> buffer;
    try
    {
      string.push(buffer);
    }
    catch (std::overflow_error & error)
    {
      std::cerr << error.what();
      return 1;
    }
  }
  while (std::cin && string.data[string.size - 1] != '\n');
  if (!std::cin && !string.size)
  {
    std::cerr << "incorrect input\n";
    return 1;
  }
  if (string.size == 1)
  {
    std::cerr << "null string\n";
    return 1;
  }
  turkin::String result(string.size + 1);
  std::cout << turkin::isRepeat(string) << '\t' << turkin::deleteNumbers(result.data, string.data, string.size) << '\n';
  return 0;
}
