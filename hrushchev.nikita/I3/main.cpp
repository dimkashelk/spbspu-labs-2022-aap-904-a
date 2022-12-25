#include <iostream>
#include "unitestring.hpp"
#include "existconsecutiveequalelement.hpp"
#include "generatealphabeticchar.hpp"

int main()
{
  size_t capacity = 10;
  char* c_string = new char[capacity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* new_str = new char[capacity + 20];
        for (auto i = c_string, j = new_str; i != c_string + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] c_string;
        c_string = new_str;
        capacity += 20;
      }
      catch (...)
      {
        delete[] c_string;
        return 1;
      }
    }
    std::cin >> c_string[size];
  }
  while (std::cin && c_string[size++] != '\n');

  if (size <= 1)
  {
    std::cerr << "Empty input\n";
    delete[] c_string;
    return 1;
  }
  c_string[size - 1] = '\0';
  std::cout << c_string << "\n";

  std::srand(time(0));
  const size_t rand_size = 10 + std::rand() % 30;
  char* rand_string = nullptr;

  try
  {
    rand_string = new char[rand_size];
    for (size_t i = 0; i < rand_size; i++)
    {
      rand_string[i] = generateAlphabeticChar();
    }
    rand_string[rand_size - 1] = '\0';
    std::cout << rand_string << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";\
    delete[] c_string;
    delete[] rand_string;
    return 1;
  }

  char* united_string = nullptr;
  try
  {
    united_string = new char[size + rand_size];
    united_string = uniteString(united_string, c_string, rand_string);
    std::cout << united_string << '\n';
    std::cout << exist_consecutive_equal_element(united_string) << "\n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] c_string;
    delete[] rand_string;
    delete[] united_string;
  }

  delete[] c_string;
  delete[] rand_string;
  delete[] united_string;
}
