#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "charArray.h"
#include "stringTransform.h"

int main()
{
  const size_t basicCapacity = 10;
  const size_t basicAddition = 10;
  turkin::CharArray array(basicCapacity);
  std::cin >> std::noskipws;
  do
  {
    if (array.size < array.capacity)
    {
      std::cin >> array.data[array.size++];
    }
    else
    {
      try
      {
        array.data = turkin::extend(array, basicAddition);
      }
      catch (const std::overflow_error & error)
      {
        std::cerr << error.what();
        return 1;
      }
    }
  }
  while (std::cin && array.data[array.size - 1] != '\n');
  if (!std::cin && !array.size)
  {
    std::cerr << "incorrect input\n";
    return 1;
  }
  if (array.size == 1)
  {
    std::cerr << "null string\n";
    return 1;
  }
  array.data[array.size] = '\0';

  char * result = new char[array.size]();
  turkin::deleteNumbers(result, array.data);
  std::cout << turkin::isRepeat(array.data) << '\t' << result << '\n';
  delete [] result;
  return 0;
}
