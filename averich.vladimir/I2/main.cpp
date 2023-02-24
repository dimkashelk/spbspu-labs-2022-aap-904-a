#include <iostream>
#include <fstream>
#include <cstddef>
#include "sort.hpp"
#include "istriplet.hpp"
#include "readthearray.hpp"
#include "generationdynarray.hpp"
int main(int argc, char* argv[])
{
  const size_t sizeOfDefaultArray = 10;
  int defaultArray[sizeOfDefaultArray] = { -5, 2, 1, 3, 2, 1, -2, 1, -3, -4 };
  std::cout << "Count of triplets: " << isTriplet(defaultArray, sizeOfDefaultArray) << " in the static array" << std::endl;
  sort(defaultArray, sizeOfDefaultArray);

  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of dynamic array: ";
  std::cin >> sizeOfDynArray;
  if (!std::cin)
  {
    std::cout << "Error input" << std::endl;
    return 2;
  }
  int* dynArray = new int[sizeOfDynArray];
  if (sizeOfDynArray > 0)
  {
    dynArray = generationDynArray(sizeOfDynArray);
    try
    {
      std::cout << "Count of triplets: " << isTriplet(dynArray, sizeOfDynArray) << " in the dynamic array" << std::endl;
      sort(dynArray, sizeOfDynArray);
      delete[] dynArray;
    }
    catch (std::length_error& e)
    {
      std::cout << e.what() << std::endl;
      delete[] dynArray;
    }
  }
  else
  {
    std::cout << "Error dynamic array" << std::endl;
    delete[] dynArray;
  }

  if (argc != 2)
  {
    std::cout << "Error: incorrect file name";
    return 1;
  }
  std::string fileName = argv[1];
  std::ifstream in(fileName);
  size_t sizeOfFileArray = 0;
  in >> sizeOfFileArray;
  int* array = new int[sizeOfFileArray];
  try
  {
    int* fileArray = readTheArray(in, sizeOfFileArray, array);
    std::cout << "Count of triplets: " << isTriplet(fileArray, sizeOfFileArray) << " in the file array" << std::endl;
    sort(fileArray, sizeOfFileArray);
    delete[] fileArray;
  }
  catch (const std::length_error& e)
  {
    std::cout << e.what() << std::endl;
    delete[] array;
    return 1;
  }
  delete[] array;
  return 0;
}
