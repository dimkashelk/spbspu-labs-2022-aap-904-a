#include <iostream>
#include <extendcstring.hpp>
#include "isfloat.hpp"

int main()
{
  size_t capacity = 10;
  char * cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        cstring = extendCString(cstring, capacity, size);
      }
      catch (const std::exception & e)
      {
        std::cerr << e.what() << "\n";
	delete [] cstring;
	return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (!std::cin)
  {
    std::cout << "Error\n";
    delete [] cstring;
    return 1;
  }
  cstring[size - 1] = '\0';
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cout << "Empty string\n";
    delete [] cstring;
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete [] cstring;
}

