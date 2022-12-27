#include <iostream>
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
        for (auto i = c_string, j = newstr; i != c_string + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] c_string;
        c_string = newstr;
        capacity += 10;
        if (c_string[0] == '\n')
        {
          delete[] c_string;
          std::cerr << "Error: empty string \n";
          return 2;
        }
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

  c_string[size - 1] = '\0';

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

  try
  {
    repeatSymbols(repeat_symbols, c_string);
  }
  catch (const std::bad_alloc &e)
  {
    delete[] c_string;
    std::cerr << "Error: \n" << e.what();
    return 1;
  }
  catch (const std::overflow_error &e)
  {
    delete[] c_string;
    delete[] repeat_symbols;
    std::cerr << "Error: \n" << e.what();
    return 3;
  }

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
