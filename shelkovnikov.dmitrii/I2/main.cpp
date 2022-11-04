#include <iostream>
#include <fstream>
int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    std::cout << "Too much parameters";
    return -1;
  }
  int n;
  std::cin >> n;
  std::ifstream in;
  in.open(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file";
    return -1;
  }
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    if (in.eof())
    {
      std::cout << "There are fewer numbers in file";
      return -1;
    }
    in >> arr[i];
  }
  if (!in.eof())
  {
    std::cout << "Too much numbers in file";
    return -1;
  }
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  return 0;
}
