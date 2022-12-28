#include <iostream>
#include <cstring>
#include "RepeatSymbols.hpp"
#include "Vowel.hpp"
int main()
{
  size_t capacity = 10;
  size_t size = 0;

  char *c_string = new char[capacity];

  c_string[0] = '\n';

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *newstr = new char[capacity + 10];
        c_string[capacity - 1] = '\0';
        strcpy(newstr, c_string);
        delete[] c_string;
        c_string = newstr;
        capacity += 10;
      }
      catch (const std::bad_alloc &e)
      {
        std::cerr << "Error: " << e.what();
        return 1;
      }
    }
    std::cin >> c_string[size];
  }
  while (std::cin && c_string[size++] != '\n');

  if (c_string[0] == '\n')
  {
    delete[] c_string;
    std::cerr << "Error: empty string \n";
    return 2;
  }

  c_string[size] = '\0';

  // task 6

  char *repeat_symbols = nullptr;

  try
  {
    repeat_symbols = new char[capacity];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] c_string;
    std::cout << "Error:\n";
    std::cout << e.what();
    return 3;
  }

  repeatSymbols(repeat_symbols, c_string);

  std::cout << "Repeat symbols string: " << repeat_symbols << '\n';

  // task 18

  char *vowel_symbols = nullptr;

  try
  {
    vowel_symbols = new char[12];
    findVowel(vowel_symbols, c_string);
  }
  catch (const std::bad_alloc &e)
  {
    delete[] c_string;
    delete[] repeat_symbols;
    std::cerr << "Error: \n" << e.what();
    return 1;
  }
  catch (const std::overflow_error &e)
  {
    delete[] c_string;
    delete[] repeat_symbols;
    delete[] vowel_symbols;
    std::cerr << "Error: \n" << e.what();
    return 3;
  }

  std::cout << "Latin vowel symbols string: " << vowel_symbols << '\n';

  delete[] c_string;
  delete[] repeat_symbols;
  delete[] vowel_symbols;
}
