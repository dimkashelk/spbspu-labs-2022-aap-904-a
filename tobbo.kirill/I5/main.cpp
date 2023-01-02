#include<iostream>
#include<string>
#include "isreal.h"

int main()
{
  std::string line;
  if (std::getline(std::cin, line) && !line.empty())
  {
    if (isReal(line))
    {
      std::cout << line << " true\n";
    }
    else
    {
      std::cout << line << " false\n";
    }
  }
  else
  {
    std::cerr << "Error input!\n";
    return 1;
  }
  return 0;
}
