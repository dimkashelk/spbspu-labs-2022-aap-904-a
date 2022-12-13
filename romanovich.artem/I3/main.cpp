#include "hasRepeatingElements.h"
#include <iostream>
#include <limits>
int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  size_t maxSize = std::numeric_limits< size_t >::max();
  do
  {
    if (size == capacity)
    {
      if (capacity == maxSize)
      {
        std::cout << "Too long string.\n";
        return 1;
      }

      try
      {
        char *newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  } while (std::cin && cstring[size++] != '\n');
  if (!std::cin && !array.size)
  {
    delete [] cstring;
    std::cerr << "Input incorrect.\n";
    return 1;
  }
  if (cstring[0] == '\n' || cstring[0] == '\0')
  {
    delete [] cstring;
    std::cerr << "No string provided.\n";
    return 1;
  }
  cstring[size - 1] = '\0';
  try
  {
    std::cout << std::boolalpha << hasRepeatingElements(cstring) << "\n";
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] cstring;
    return 1;
  }
  try
  {
    const char *stringCompare = "Why did a C++ programmer cross the street? What for? To pick up trash! HAHAHAHAHAHA!";
    std::cout << std::boolalpha << hasRepeatingElements(cstring, stringCompare) << "\n";
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] cstring;
    return 1;
  }
  delete[] cstring;
}
