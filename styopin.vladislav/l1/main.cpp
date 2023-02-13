#include <iostream>
#include "Count.h"

int main()
{
  unsigned int countMinimum = 0;
  int checking = 0;
  int value = 0;
  int previous_value = 0;
  unsigned int countSignChanges = 0;

  do {
    std::cin >> value;

    try {
      counterMin(countMinimum, previous_value, value, checking);
      counterSignChanges(countSignChanges, previous_value, value);
    } catch (const std::overflow_error& e) {
      std::cout << e.what() << '\n';
      return 1;
    }

    previous_value = value;
  }
  while (value && std::cin);

  if (!std::cin) {
    std::cout << "Error...\n";
  }
  std::cout << "Number of local minimums: " << countMinimum << "\n";
  std::cout << "Number of sign changes: " << countSignChanges << "\n";
}

