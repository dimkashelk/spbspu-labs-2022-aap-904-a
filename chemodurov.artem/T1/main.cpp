#include <iostream>
#include <string>

int main()
{
  std::string line = "";
  do
  {
    std::getline(std::cin, line);
    if (!line.compare(0, 8, "POLYGON"))
    {
      
    }
  }
  while (std::cin);
  return 0;
}
