#include<iostream>
#include "countdifferentletters.h"
#include "countrepeatedsymbols.h"

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
        char * newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete [] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  cstring[size - 1] = '\0';

  std::cout << cstring << "\n";
  int resultlen = 0;
  char* res1 = new char[size];
  std::cout << count_different_letters( res1, cstring, resultlen) << std::endl;
  std::cout << count_repeated_symbols(cstring) << std::endl;
  delete [] cstring;
}