#include "array.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  const size_t staticArrSize = 8;
  const int staticArr[staticArrSize] = {1, -234, -253, 12323, 2353, -2341, 42342, -12312};
  int lowBound = -10000;
  int highBound = 10000;
  try {
    std::cout << odintsov::findMax(staticArr, staticArrSize, lowBound, highBound) << '\n';
    std::cout << odintsov::getAvgEvenIndices(staticArr, staticArrSize) << '\n';
  } catch(const std::logic_error& err) {
    std::cout << err.what() << '\n';
    return 1;
  }
  size_t dynArrSize = 0;
  std::cin >> dynArrSize;
  odintsov::Array dynArr = odintsov::Array(dynArrSize);
  for (size_t i = 0; i < dynArrSize; i++) {
    dynArr.data[i] = rand() % highBound;
  }
  try {
    std::cout << odintsov::findMax(dynArr.data, dynArrSize, lowBound, highBound) << '\n';
    std::cout << odintsov::getAvgEvenIndices(dynArr.data, dynArrSize) << '\n';
  } catch(const std::logic_error& err) {
    std::cout << err.what() << '\n';
    return 2;
  }
}
