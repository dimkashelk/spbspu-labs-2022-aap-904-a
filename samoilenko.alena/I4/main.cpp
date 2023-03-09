#include <iostream>
#include <fstream>
#include <cstring>
#include "columns_without_null_elements.h"
#include "rows_without_same_elements.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "File or parameters are incorrect";
    return 1;
  }
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cout << "Error during opening the file input.txt";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (!output)
  {
    std::cout << "Error during opening the file input.txt";
    input.close();
    output.close();
  }
  return 0;
}