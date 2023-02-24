#include <iostream>
#include <fstream>
#include <cstddef>
#include "sort.hpp"
#include "istriplet.hpp"
#include "readthearray.hpp"
#include "generationdynarray.hpp"
int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Error: incorrect file name";
    return 1;
  }
  const size_t sizeOfDefaultArray = 10;
  int defaultArray[sizeOfDefaultArray] = { -5, 2, 1, 3, 2, 1, -2, 1, -3, -4 };
  std::cout << "Count of triplets: " << isTriplet(defaultArray, sizeOfDefaultArray) << " in the static array" << std::endl;
  sort(defaultArray, sizeOfDefaultArray);

  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of dynamic array: ";
  std::cin >> sizeOfDynArray;
  if (!std::cin)
  {
    std::cerr << "Dynamic array is empty" << std::endl;
    return 1;
  }
  int* dynArray = generationDynArray(sizeOfDynArray);
  std::cout << "Count of triplets: " << isTriplet(dynArray, sizeOfDynArray) << " in the dynamic array" << std::endl;
  sort(dynArray, sizeOfDynArray);
  delete[] dynArray;

  size_t sizeOfFileArray = 0;
  int* array = new int[sizeOfFileArray];
  try
  {
    int* fileArray = readTheArray(argv[1], sizeOfFileArray, array);
    std::cout << "Count of triplets: " << isTriplet(fileArray, sizeOfFileArray) << " in the file array" << std::endl;
    sort(fileArray, sizeOfFileArray);
    delete[] fileArray;
  }
  catch (...)
  {
    std::cerr << "File or array in file is empty" << std::endl;
    return 1;
  }
  delete[] array;
  return 0;
}
