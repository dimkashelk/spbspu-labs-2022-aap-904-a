#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
int main(int argc, char *argv[])
{
  if (argc > 4)
  {
    std::cout << "Too much parameters";
    return 1;
  }
  if (argc != 4)
  {
    std::cout << "Pls check parameters";
    return 1;
  }

  return 0;
}
