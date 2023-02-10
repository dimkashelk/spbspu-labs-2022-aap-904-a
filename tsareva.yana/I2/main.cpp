#include <stdexcept>
#include <iostream>
#include <fstream>
#include "counterpositiveelements.h"
#include "countersimilarelements.h"
int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cout << "No file name.";
    return 1;
  }
  if (argc > 2)
  {
    std::cout << "There are a lot of parameters";
    return 1;
  }
  int a1[] = {1, 1, 1, 1, 1, 1, 1};
  std::cout << count_positive_elements(a1, 7) << std::endl;
  std::cout << count_similar_elements(a1, 7) << std::endl;
  size_t n = 0;
  std::cin >> n;
  int *a2 = new int[n];
  std::srand(time(nullptr));
  for (size_t i = 0; i < n; i++)
  {
    a2[i] = std::rand();
  }
  std::cout << count_positive_elements(a2, n) << std::endl;
  std::cout << count_similar_elements(a2, n) << std::endl;
  delete[] a2;
  std::ifstream in(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error =(";
    return 1;
  }
  while (!in.eof())
  {
    size_t size = 0;
    in >> size;
    if (!in)
    {
      std::cout << "Error... =(";
      return 1;
    }
    int *a3 = new int[size];
    for (size_t i = 0; i < size; i++)
    {
      in >> a3[i];
      if (!in)
      {
        std::cout << "Error... =(";
        delete[] a3;
        return 1;
      }
    }
    std::cout << count_positive_elements(a3, size) << "\n";
    std::cout << count_similar_elements(a3, size) << "\n";
    delete[] a3;
  }
  return 0;
}
