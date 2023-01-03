#include <iostream>
#include <makecstring.hpp>

int main()
{
  size_t size = 0;
  size_t capacity = 10;
  char *c_string = new char[capacity];

  c_string[0] = '\n';

  try
  {
    c_string = makeCString(c_string, size, capacity, std::cin);
  }
  catch (std::bad_alloc &e)
  {
    std::cerr << "Error: " << e.what();
    delete[] c_string;
    return 1;
  }

  if (c_string[0] == '\n')
  {
    std::cout << "Empty string";
    delete[] c_string;
    return 2;
  }

  c_string[size] = '\0';

  std::cout << c_string << '\n';

  delete[] c_string;
  return 0;
}
