#include <iostream>
#include "formNewStringVarFiveteen.h"
#include <fstream>
#include "formNewStringVarFive.h"
int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
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
  cstring[size - 1] = '\0';
  if (size == 0 or size == 1)
  {
    std::cerr << "Empty input" << '\n';
    delete[] cstring;
    return -1;
  }
  std::cout << cstring << "\n";
  delete[] cstring;
}