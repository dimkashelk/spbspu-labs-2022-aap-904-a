#include<iostream>
#include<fstream>

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "The arguments are not correct!\n";
  }
  std::ifstream input(argv[2]);
}
