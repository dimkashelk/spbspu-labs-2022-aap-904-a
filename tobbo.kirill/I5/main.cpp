#include<iostream>
#include<string>
#include "isreal.h"

int main()
{
  std::string line;
  if (std::getline(std::cin, line) && !line.empty())
  {
    std::cout << std::boolalpha << isReal(line) << "\n";
  }
  else
  {
    std::cerr << "Error input!\n";
    return 1;
  }
  return 0;
}
