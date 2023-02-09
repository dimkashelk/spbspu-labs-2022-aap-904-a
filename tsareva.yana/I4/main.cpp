#include<iostream>
#include<fstream>
#include <cstddef>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "The arguments are not correct!\n";
    return 1;
  }
  std::ifstream inputfile(argv[2]);
  if (!inputfile)
  {
    std::cerr << "Error file\n";
    return 1;
  }
  size_t row = 0;
  inputfile >> row;
  if (!inputfile)
  {
    std::cerr << "Incorrect arguments of the matrix\n";
    return 1;
  }
  size_t column =0 ;
  inputfile >> column;
  if (!inputfile)
  {
    std::cerr << "Incorrect arguments of the matrix\n";
    return 1;
  }
  size_t size = row * column;
  std::ofstream outputfile(argv[3]);
  if (!outputfile)
  {
    std::cerr << "Error file";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    if (size > 1000)
    {
      std::cerr << "Too much elements\n";
      return 1;
    }

  }
}
