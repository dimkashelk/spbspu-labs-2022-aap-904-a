#include <iostream>
#include <cstddef>
#include <cstring>
#include <inputString.h>
#include "change_register.h"
#include "generate_new_line.h"
int main()
{
  size_t capacity_1 = 10;
  size_t size_1 = 0;
  char * str_1 = nullptr;
  try
  {
    str_1 = inputStr(std::cin, size_1, capacity_1);
  }
  catch (...)
  {
    std::cerr << "error";
    return 1;
  }
  const char * str_2 = "abcdefgh";
  const size_t size_2 = std::strlen(str_2);
  try
  {
    char * res1 = new char[size_1 + size_2 - 1];
    generateNewLine(res1, str_1, str_2);
    std::cout << res1 << '\n';
    delete[] res1;
  }
  catch (const std::bad_alloc & e)
  {
    std::cout << e.what();
    delete[] str_1;
    return 2;
  }
  try
  {
    char * res2 = new char[size_1];
    changeRegister(res2, str_1);
    std::cout << res2 << '\n';
    delete[] res2;
  }
  catch (const std::bad_alloc & e)
  {
    std::cout << e.what();
    delete[] str_1;
    return 2;
  }
  delete[] str_1;
  return 0;
}
