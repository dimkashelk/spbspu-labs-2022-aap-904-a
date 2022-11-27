#include "CounterLocalMin.h"
#include "CounterChanges.h"
#include <iostream>
#include <limits>

int main() {
  unsigned int countMin = 0;
  int checking = 0;
  int value = 0;
  int prevV = 0;
  unsigned int countChanges = 0;

  do {
    std::cin >> value;

    try
    {
      counterMin(countMin, prevV, value, checking);
      if (countChanges == std::numeric_limits<unsigned int>::max())
      {
        throw std::overflow_error("Overflow");
      }
    }
    catch (const std::overflow_error& e)
    {
      std::cout << e.what() << '\n';
      return 1;
    }

    countChanges += counterChanges(prevV, value);
    prevV = value;
  }
  while (value && std::cin);

   if (!std::cin) {
     std::cout << "Error...\n";
   }
   std::cout << "Number of local minimums: " << countMin << "\n";
   std::cout << "Number of sign changes: " << countChanges << "\n";
}
