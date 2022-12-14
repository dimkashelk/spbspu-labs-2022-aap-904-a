#include <iostream>
#include "remove_extra_spaces.h"
#include "delete_identical_chars.h"

int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;

  std::cout << "Please input first string" << '\n';
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
  size--;

  char *destination = new char[size];
  std::cout << "First string without extra spaces: '" << remove_extra_spaces(destination, cstring) << "'\n";
  delete [] destination;

  std::cout <<"Please input second string: " << '\n';
  size_t capacity_second = 10;
  char *cstring_second = new char[capacity_second];
  size_t size_second = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size_second == capacity_second)
    {
      try
      {
        char * newstr = new char[capacity_second + 20];
        for (auto i = cstring_second, j = newstr; i != cstring_second + size_second; ++i, ++j)
        {
          *j = *i;
        }
        delete [] cstring_second;
        cstring_second = newstr;
        capacity_second += 20;
      }
      catch (...)
      {
        delete [] cstring_second;
        return 1;
      }
    }
    std::cin >> cstring_second[size_second];
  }
  while (std::cin && cstring_second[size_second++] != '\n');
  cstring_second[size_second - 1] = '\0';

  char *destination_2 = new char[size];
  std::cout << "First string without chars in second string: '" << delete_identical_chars(destination_2, cstring, cstring_second) << "'\n";
  delete [] destination_2;

  delete [] cstring;
  delete [] cstring_second;
}
