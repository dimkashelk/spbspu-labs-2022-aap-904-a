#include <iostream>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cout << "Error with arguments";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    return 0;
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    return 0;
  }
  else
  {
    std::cout << "Incorect arg " << argv[1] << "\n";
    return 1;
  }
}