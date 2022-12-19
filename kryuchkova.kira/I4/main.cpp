#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>

main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cout << "Invalid number of arguments." << '\n';
    return 1;
  }
  size_t n = 0;
  size_t m = 0;
  std::ifstream file(argv[2]);
  file >> n >> m;
  if (!file)
  {
    std::cout << "Error";
    return 1;
  }
}
