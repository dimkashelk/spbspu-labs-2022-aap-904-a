#include <iostream>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cout << "Error with arguments";
    return 1;
  }
  return 0;
}