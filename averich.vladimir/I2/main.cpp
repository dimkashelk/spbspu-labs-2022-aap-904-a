#include <iostream>
#include <fstream>
#include "sort.hpp"
int main(int argc, char * argv[])
{
  if (argc != 2)
  {
    std::cout << "Error: wrong file name" << std::endl;
    return 2;
  }
  const size_t sizeOfDefaultArray = 10;
  int defaultArray[sizeOfDefaultArray] = { -5, 2, 1, 3, 2, 1, -2, 1, -3, -4 };
  sort(defaultArray, sizeOfDefaultArray);
  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of array: ";
  std::cin >> sizeOfDynArray;
  int* dynArray = new int[sizeOfDynArray];
  std::srand(time(nullptr));
  for (size_t i = 0; i < sizeOfDynArray; i++)
  {
    dynArray[i] = 1 + rand() % 9;
    dynArray[i] = 1 + rand() % 9 * -1;
  }
  sort(dynArray, sizeOfDynArray);
  delete[] dynArray;
  std::string fileName = argv[1];
  std::ifstream in(fileName);
  size_t sizeOfFileArray = 0;
  in >> sizeOfFileArray;
  int * fileArray = new int[sizeOfFileArray];
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      std::cout << "Error: input is empty" << std::endl;
      in.close();
      delete[] fileArray;
      return 2;
    }
  }
  sort(fileArray, sizeOfFileArray);
  delete[] fileArray;
  return 0;
}
