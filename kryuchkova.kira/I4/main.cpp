#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include "unique_elements.h"

int main()
{
  // if (argc != 4)
  // {
  //   std::cout << "Invalid number of arguments." << '\n';
  //   return 1;
  // }
  // size_t n = 0;
  // size_t m = 0;
  // std::ifstream file(argv[2]);
  // file >> n >> m;
  // if (!file)
  // {
  //   std::cout << "Error";
  //   return 1;
  // }
  int matrix[20] = {5, 1, 2, 3, 4, 
                    5, 1, 7, 8, 9,
                    5, 11, 12, 3, 14,
                    15, 16, 2, 18, 19};
  std::cout << unique_elements(matrix, 4, 5) << '\n';
  
}
