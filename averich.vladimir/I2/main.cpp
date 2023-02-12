#include <iostream>
#include <fstream>
#include <cstddef>
#include "sort.hpp"
#include "istriplet.hpp"
#include "readthearray.hpp"
#include "generationdynarray.hpp"
int main(int argc, char * argv[])
{
  if (argc != 2)
  {
   std::cerr << "Error: wrong file name" << std::endl;
   return 1;
  }
  const size_t sizeOfDefaultArray = 10;
  int defaultArray[sizeOfDefaultArray] = {-5, 2, 1, 3, 2, 1, -2, 1, -3, -4};
  std::cout << "Count of triplets: " << isTriplet(defaultArray, sizeOfDefaultArray) << " in the static array" << std::endl;
  sort(defaultArray, sizeOfDefaultArray);
  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of dynamic array: ";
  std::cin >> sizeOfDynArray;
  if (!std::cin)
  {
    std::cerr << "Error: invalid input" << std::endl;
    return 1;
  }
  generationDynArray(sizeOfDynArray);
  try
  {
    readTheArray(argv[1]);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
