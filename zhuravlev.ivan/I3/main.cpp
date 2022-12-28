#include<iostream>
#include <exception>
#include "finder_three_elements.h"
#include "finder_same_elements_in_two_strings.h"

int main()
{
  size_t capacity = 10;
  char * cstring = new char[capacity];
  const size_t static_string_size = 10;
  const char* static_string = "abcABC123456";
  size_t size = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char * newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (std::bad_alloc &e)
      {
        delete [] cstring;
        std::cerr << e.what();
      }
    }
      std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (size == 0)
  {
    std::cerr << "Error: Something wrong with input!" << "\n";
    delete [] cstring;
    return 1;
  }
  else
  {
    cstring[size - 1] = '\0';
    finderThreeSameElements(cstring, size);
    finderSameElementsInTwoStrings(cstring, static_string, size, static_string_size);
    delete [] cstring;
    return 0;
  }
}
