#include "Lab1.h"
#include <iostream>

int main() {
  int value = 0;
  int prevV = 0;
  int countMin = 0;
  bool check = false;
  int countChanges = 0;

  do {
    std::cin >> value;
    countChanges += counterChanges(prevV, value);

    if (check && prevV < value && value != 0) {
      countMin += 1;
    }
    check = checkingFirstTwoValues(prevV, value);

    prevV = value;
  }
  while (value && std::cin);

   if (!std::cin) {
     std::cout << "Error...\n";
   }
   std::cout << "Number of local minimums: " << countMin << "\n";
   std::cout << "Number of sign changes: " << countChanges << "\n";
}
