#include <iostream>
#include <fstream>
#include <cstddef>
#include <limits>
#include "sortoutput.hpp"
#include "istriplet.hpp"
#include "readthearray.hpp"
#include "generationdynarray.hpp"
int main(int argc, char* argv[])
{
  const size_t maxSize = std::numeric_limits< size_t >::max();
  int defaultArray[10] = { -5, 2, 1, 3, 2, 1, -2, 1, -3, -4 };
  std::cout << "Count of triplets: " << isTriplet(defaultArray, 10) << " in the static array" << "\n";
  sortOutput(defaultArray, 10);
  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of dynamic array: ";
  std::cin >> sizeOfDynArray;
  if (!std::cin)
  {
    std::cout << "Error input" << "\n";
    return 2;
  }
  std::srand(time(nullptr));
  int* dynArray = new int[sizeOfDynArray];
  if (sizeOfDynArray > 0)
  {
    dynArray = generationDynArray(dynArray, sizeOfDynArray);
    try
    {
      std::cout << "Count of triplets: " << isTriplet(dynArray, sizeOfDynArray) << " in the dynamic array" << "\n";
      sortOutput(dynArray, sizeOfDynArray);
      delete[] dynArray;
    }
    catch (std::length_error& e)
    {
      std::cout << e.what() << "\n";
      delete[] dynArray;
      return 2;
    }
  }
  else
  {
    std::cout << "Error dynamic array" << "\n";
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
  if (!in)
  {
    std::cout << "Error reading file" << "\n";
    return 1;
  }
  if (sizeOfFileArray > 0)
  {
    int* array = new int[sizeOfFileArray];
    int* fileArray = readTheArray(in, sizeOfFileArray, array, maxSize);
    sortOutput(fileArray, sizeOfFileArray);
    try
    {
      std::cout << "Count of triplets: " << isTriplet(fileArray, sizeOfFileArray) << " in the file array" << "\n";
      delete[] fileArray;
    }
    catch (const std::length_error& e)
    {
      std::cout << e.what() << "\n";
      delete[] array;
      return 2;
    }
  }
  return 0;
}
