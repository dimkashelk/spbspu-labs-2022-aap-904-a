#include <iostream>
#include "charstr.h"

int main()
{
  size_t capacity = 20;
  char * c_string = new char[capacity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        size_t new_capacity = capacity + 20;
        char * new_string = chemodurov::extendCString(c_string, capacity, new_capacity);
        delete [] c_string;
        c_string = new_string;
        new_string = nullptr;
        capacity = new_capacity;
      }
      catch (const std::bad_alloc & e)
      {
        delete [] c_string;
        return 1;
      }
    }
    std::cin >> c_string[size];
  }
  while (std::cin && c_string[size++] != '\n');

  if (c_string[0] == '\n' || c_string[0] == '\0')
  {
    std::cerr << "Empty string\n";
    delete [] c_string;
    return 1;
  }
  c_string[size - 1] = '\0';

  size_t other_size = 5;
  char * other_string = new char[other_size];
  for (size_t i = 0; i < other_size - 1; ++i)
  {
    other_string[i] = '2';
  }
  other_string[other_size] = '\0';
  char * another_string = chemodurov::addNumbersToFirst(c_string, other_string);
  std::cout << another_string << "\n";

  bool is_rep_num = chemodurov::isRepeatingNumbers(c_string);
  if (is_rep_num)
  {
    std::cout << "String contains repeating numbers\n";
  }
  else
  {
    std::cout << "String not contains repeating numbers\n";
  }

  char * yet_another_string = chemodurov::deleteVowels(c_string);
  std::cout << yet_another_string << "\n";
  delete [] c_string;
  delete [] other_string;
  delete [] another_string;
  delete [] yet_another_string;
}
