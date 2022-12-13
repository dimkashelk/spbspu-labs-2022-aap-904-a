#include<iostream>
#include <limits>
int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  size_t maxSize = std::numeric_limits<size_t>::max();
  do
  {
    if (size == capacity)
    {
      if (capacity == maxSize)
      {
        std::cout << "Too long string";
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
  cstring[size - 1] = '\0';
  std::cout << cstring << "\n";
  delete[] cstring;
}