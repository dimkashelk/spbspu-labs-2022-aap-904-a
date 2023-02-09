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
  }
}
