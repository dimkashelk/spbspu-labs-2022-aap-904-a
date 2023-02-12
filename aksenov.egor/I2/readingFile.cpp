#include "readingFile.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
int *readFile(std::string fn, size_t line)
{
  std::ifstream input(fn);
  input >> line;
  int *f_arr = new int[line];
  if (!input)
  {
    input.close();
    delete [] f_arr;
    throw std::length_error("File error");
  }
  for (size_t i = 0; i < line; ++i)
  {
    input >> f_arr[i];
    if (!input)
    {
      std::cout << "ERROR" << "\n";
      input.close();
      delete [] f_arr;
      throw std::length_error("File error");
    }
  }
  return f_arr;
}
