#include <iostream>
#include "latin_letters.h"
#include "most_common_characters.h"

int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  const size_t newsize = 27;
  const size_t newnewsize = 4;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (const std::bad_alloc& ex)
      {
        delete [] cstring;
        std::cerr << "Error..." << '\n';
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (size == 0 || cstring[0] == '\n')
  {
    std::cerr << "Error..." << '\n';
    delete [] cstring;
    return 1;
  }
  cstring[size - 1] = '\0';
  std::cout << cstring << "\n";
  char* newstring = nullptr;
  try
  {
    newstring = new char[newsize];
  }
  catch (const std::bad_alloc& ex)
  {
    delete [] cstring;
    std::cerr << "Error..." << '\n';
    return 1;
  }
  std::cout << createStringNewLatinLetters(newstring, cstring);
  std::cout << '\n';
  delete [] newstring;
  try
  {
    newstring = new char[newnewsize];
  }
  catch (const std::bad_alloc& ex)
  {
    delete [] cstring;
    std::cerr << ex.what() << '\n';
    return 1;
  }
  std::cout << printMostCommonCharacters(newstring, cstring);
  std::cout << '\n';
  delete [] newstring;
  delete [] cstring;
  return 0;
}
