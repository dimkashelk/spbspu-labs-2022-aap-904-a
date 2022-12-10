#include<iostream>
#include "countdifferentletters.h"
#include "countrepeatedsymbols.h"

size_t countt_different_letters(char* destination, const char* source, int len)
{
  size_t di = 0;
  destination[di] = '\0';
  size_t si = 0;
  int count = 0;
  while (source[si] != '\0')
  {
    std::size_t si2 = si + 1;
    while (source[si2] != '\0')
    {
      if (source[si] == source[si2])
      {
        count++;
      }
      ++si2;
    }
    if (count == 0)
    {
      destination[di] = source[si];
      ++di;
      destination[di] = '\0';
    }
    count = 0;
    ++si;
  }
  while (destination[len] != '\0')
  {
    ++len;
  }
  return len;
}

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
  if (!std::cin && !size)
  {
    std::cout << "error";
    delete[] cstring;
    return 1;
  }
  cstring[size - 1] = '\0';
  std::cout << cstring << "\n";
  int resultlen = 0;
  char* res1 = new char[size];
  std::cout << countt_different_letters(res1, cstring, resultlen) << std::endl;
  std::cout << count_repeated_symbols(cstring, capacity) << std::endl;
  delete [] cstring;
}
