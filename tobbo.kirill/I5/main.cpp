#include<iostream>
#include<fstream>
#include<string>
#include "isreal.h"


int main(int argc, char* argv[])
{
  std::ifstream fin(argv[1]);
  if (!fin)
  {
    std::cerr << "Error while rading from file\n";
    return 1;
  }

  std::string str;
  while (fin >> str)
  {
    if (isReal(str))
      std::cout << str << " True\n";
    else
      std::cout << str << " False\n";
  }
  fin.close();
  return 0;
}
