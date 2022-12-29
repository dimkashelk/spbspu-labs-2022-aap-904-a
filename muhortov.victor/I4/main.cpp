#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: 4 arguments nof found\n";
    return 1;
  }

  return 0;
}