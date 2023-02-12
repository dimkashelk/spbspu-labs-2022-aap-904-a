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
   std::cerr << "Error: incorrect file name";
   return 1;
  }
  const size_t sizeOfDefaultArray = 10;
  int defaultArray[sizeOfDefaultArray] = {-5, 2, 1, 3, 2, 1, -2, 1, -3, -4};
  try
  {
    std::cout << "Count of triplets: " << isTriplet(defaultArray, sizeOfDefaultArray) << " in the static array" << std::endl;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 1;
  }
  try
  {
    sort(defaultArray, sizeOfDefaultArray);
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    return 1;
  }
  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of dynamic array: ";
  std::cin >> sizeOfDynArray;
  if (!std::cin)
  {
    throw std::logic_error("Error: invalid input");
    return 1;
  }
  try
  {
    generationDynArray(sizeOfDynArray);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 1;
  }
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
