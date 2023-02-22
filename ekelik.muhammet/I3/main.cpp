#include <iostream>
#include <cstddef>
#include <my_String.h>
#include "common_symbols.h"
#include "uncommon_symbols.h"

int main()
{
  size_t size = 0;
  size_t capacity = 10;

  char* my_string = makeMyString(size, capacity, std::cin);

  if (my_string[0] == '\n')
  {
    delete[] my_string;
    std::cerr << "Error: empty string \n";
    return 2;
  }

  // Task 5
  char* my_symbols = nullptr;
  try
  {
    my_symbols = new char[size + 1];
    my_symbols[size] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: \n" << e.what();
    delete[] my_string;
    return 1;
  }
  find_uncommon_symbols(my_symbols, my_string);
  std::cout << "Uncommon symbols: " << my_symbols << '\n';

  // Task 19
  size_t symbols = 0;
  char* my_common_symbols = nullptr;
  try
  {
    my_common_symbols = new char[4];
    my_common_symbols[symbols] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: \n" << e.what();
    delete[] my_string;
    delete[] my_symbols;
    return 1;
  }
  find_common_symbols(my_common_symbols, my_string, symbols);
  std::cout << "Common symbols: " << my_common_symbols << '\n';

  delete[] my_string;
  delete[] my_symbols;
  delete[] my_common_symbols;
  return 0;
}
