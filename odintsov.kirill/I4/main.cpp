#include <iostream>

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cout << "Error: Invalid arguments\n";
    return 1;
  }
  std::cout << argv[1];
}
