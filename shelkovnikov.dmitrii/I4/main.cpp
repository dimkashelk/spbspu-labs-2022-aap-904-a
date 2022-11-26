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
  size_t n = 0;
  size_t m = 0;
  std::ifstream in(argv[2]);
  in >> n >> m;
  if (argv[1] == 1)
  {
    int arr[n][m];
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        in >> arr[i][j];
      }
    }
  }
  else
  {
    int *arr = new int*[n];
    for (size_t i = 0; i < n; i++)
    {
      arr[i] = new int[m];
      for (int j = 0; j < m; j++)
      {
        in >> arr[i][j];
      }
    }
  }
  return 0;
}
