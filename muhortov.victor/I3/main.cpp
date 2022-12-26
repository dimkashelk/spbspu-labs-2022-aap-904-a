#include <iostream>
#include "MakeString.hpp"
#include "RepeatSymbols.hpp"
#include "Vowel.hpp"
int main()
{
  size_t capacity = 10;
  size_t size = 0;

  char *c_string = new char[capacity];

  c_string[0] = '\n';

  try
  {
    c_string = makeString(c_string, size, capacity, std::cin);
    if (c_string[0] == '\n')
    {
      delete[] c_string;
      std::cerr << "Error: empty string \n";
      return 2;
    }
    c_string[size - 1] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    delete[] c_string;
    std::cerr << "Error: " << e.what();
    return 1;
  }

  // task 6

  char *repeat_symbols = new char[size];

  try
  {
    repeat_symbols = repeatSymbols(repeat_symbols, c_string, size);
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
    std::cerr << "Error: \n" << e.what();
    return 3;
  }

  std::cout << "Repeat symbols string: " << repeat_symbols << '\n';

  // task 18

  char *vowel_sympols = new char[size];

  try
  {
    vowel_sympols = vowel(repeat_symbols, c_string, size);
  }
  catch (const std::bad_alloc &e)
  {
    delete[] c_string;
    delete[] vowel_sympols;
    std::cerr << "Error: \n" << e.what();
    return 1;
  }
  catch (const std::overflow_error &e)
  {
    delete[] c_string;
    delete[] vowel_sympols;
    std::cerr << "Error: \n" << e.what();
    return 3;
  }

  std::cout << "Latin vowel symbols string:" << vowel_sympols << '\n';

  delete[] c_string;
  delete[] repeat_symbols;
  delete[] vowel_sympols;
}
