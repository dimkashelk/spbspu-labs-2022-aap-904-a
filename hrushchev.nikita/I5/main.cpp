#include <iostream>
#include "isexpression.cpp"

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
  std::cout << isExpression(c_string) << "\n";
}

