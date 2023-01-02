#include<iostream>
#include<string>
#include "isreal.h"

int main()
{
  std::string line;

  while (std::getline(std::cin, line) && !line.empty()) {
    if (isReal(line))
    {
      std::cout << line << " true\n";
    }
    else
    {
      std::cout << line << " false\n";
    }
  }
  return 0;
}
