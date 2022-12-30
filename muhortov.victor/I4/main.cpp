#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: 4 arguments nof found\n";
    return 1;
  }
  size_t cols = 0;
  size_t rows = 0;
  std::ifstream in(argv[2]);
  in >> cols;
  in >> rows;

  if (!in)
  {
    std::cerr << "Error: problems with reading file\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {

    return 1;
  }
  else if (!std::strcmp(argv[1], "2"))
  {

    return 1;
  }
  return 0;
}