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
  try
  {
      std::cout << "Count of triplets: " << isTriplet(defaultArray, sizeOfDefaultArray) << " in the static array" << std::endl;
  }
  catch (const std::logic_error& e)
  {
      std::cerr << e.what();
  }
  try
  {
      sort(defaultArray, sizeOfDefaultArray);
  }
  catch (const std::logic_error& e)
  {
      std::cerr << e.what();
  }
  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of dynamic array: ";
  std::cin >> sizeOfDynArray;
  if (!std::cin)
  {
    std::cerr << "Error: invalid input of dynamic array";
  }
  else
  {
    try
    {
      generationDynArray(sizeOfDynArray);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << std::endl;
      return 0;
    }
  }
  try
  {
    readTheArray(argv[1]);
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    return 0;
  }
  return 0;
}
