#include<iostream>
#include <exception>
#include "finder_three_elements.h"
#include "finder_same_elements_in_two_strings.h"

int main()
{
  size_t capacity = 10;
  char * cstring = new char[capacity];
  const size_t static_string_size = 10;
  const char * static_string = "abcABC123456";
  size_t size = 0;

  std::cin >> std::noskipws;

  if (!std::cin)
  {
    std::cerr << "Error: Problems with input!" << "n";
    return 1;
  }
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
  cstring[size - 1] = '\0';

  std::cout << "Resualt of function finderThreeSameElements: " << "\n";
  finderThreeSameElements(cstring, size);
  std::cout << "Resualt of function finderSameElementsInTwoStrings: " << "\n";
  finderSameElementsInTwoStrings(cstring, static_string, size, static_string_size);
  delete [] cstring;
}
