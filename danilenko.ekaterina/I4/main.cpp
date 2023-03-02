#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "Check parameters";
    return 1;
  }

  std::ifstream inp_file(argv[2]);
  if (!inp_file.is_open())
  {
    std::cout << "Error. File not open" << '\n';
    return 1;
  }

  return 0;
}
