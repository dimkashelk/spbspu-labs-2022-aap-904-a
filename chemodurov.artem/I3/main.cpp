#include <iostream>
#include "charstr.h"

int main()
{
  size_t capacity = 20;
  char * c_string = new char[capacity];
  c_string[0] = '\0';
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
        std::cerr << e.what() << "\n";
        delete [] c_string;
        return 1;
      }
      catch (const std::invalid_argument & e)
      {
        std::cerr << e.what() << "\n";
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

  char * other_string = nullptr;
  size_t other_size = 5;
  try
  {
    other_string = new char[other_size];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] c_string;
    return 1;
  }
  for (size_t i = 0; i < other_size - 1; ++i)
  {
    other_string[i] = '2';
  }
  other_string[other_size] = '\0';

  char * another_string = nullptr;
  try
  {
    another_string = new char[size + other_size];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] c_string;
    delete [] other_string;
    return 1;
  }
  another_string = chemodurov::addNumbersToFirst(another_string, c_string, other_string);
  std::cout << another_string << "\n";
  delete [] other_string;
  delete [] another_string;

  bool is_rep_num = chemodurov::isRepeatingNumbers(c_string);
  if (is_rep_num)
  {
    std::cout << "String contains repeating numbers\n";
  }
  else
  {
    std::cout << "String does not contain repeating numbers\n";
  }

  char * yet_another_string = nullptr;
  try
  {
    yet_another_string = new char[size];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] c_string;
    return 1;
  }
  yet_another_string = chemodurov::deleteVowels(yet_another_string, c_string);
  std::cout << yet_another_string << "\n";
  delete [] c_string;
  delete [] yet_another_string;
}
