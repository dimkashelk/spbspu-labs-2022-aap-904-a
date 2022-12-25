#include <iostream>
#include "unitestring.hpp"
#include "existconsecutiveequalelement.hpp"

int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;

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
  }
  while (std::cin && cstring[size++] != '\n');

  if (size == 1)
  {
    std::cerr << "Empty string\n";
    delete[] cstring;
    return 1;
  }
  cstring[size - 1] = '\0';
  std::cout << cstring << "\n";

  char* rand_string = nullptr;
  char* new_string = nullptr;
  try
  {
    std::srand(time(0));
    const size_t rand_size = 10 + std::rand() % 30;
    char* rand_string = new char[rand_size];
    for (size_t i = 0; i < rand_size; i++)
    {
      rand_string[i] = static_cast< char >(64 + (std::rand() % 64));
    }
    std::cout << rand_string << "\n";
    std::cout << exist_consecutive_equal_element(rand_string) << "\n";
    try
    {
      char* new_string = new char[size + rand_size];
      new_string = unite_string(new_string, cstring, rand_string);
      std::cout << new_string << "\n";
    }
    catch (const std::bad_alloc& e)
    {
      std::cout << e.what() << "\n";
      delete[] cstring;
      delete[] rand_string;
      delete[] new_string;
      return 1;
    }
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << "\n";\
    delete[] cstring;
    delete[] rand_string;
    delete[] new_string;
    return 1;
  }
}
