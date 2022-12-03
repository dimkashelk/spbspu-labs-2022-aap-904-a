#include "array.hpp"
#include <iostream>

int main()
{
  const int staticArr[8] = {1, -234, -253, 12323, 2353, -2341, 42342, -12312};
  try {
    std::cout << findMax(staticArr, 8, 0, 11) << '\n';
    std::cout << getAvgEvenIndices(staticArr, 8) << '\n';
  } catch(const std::logic_error& err) {
    std::cout << err.what() << '\n';
    return 1;
  }
}
