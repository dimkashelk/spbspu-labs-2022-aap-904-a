#include <iostream>
#include <limits>
#include "Count.h"

int main() {
    int current_value = 0;
    int previous_value = 0;
    int countMin = 0;
    int countChanges = 0;
    int checking = 0;

    do {
        std::cin >> current_value;

        try
        {
          CountMin(countMin, prevV, value, checking);
          if (countChanges == std::numeric_limits<unsigned int>::max())
          {
            throw std::overflow_error("Error, Overflow");
          }
        }
        catch (const std::overflow_error& e)
        {
          std::cout << e.what() << std::endl;
          return 1;
        }

        countChanges += CountChanges(previous_value, current_value);
        previous_value = current_value;

    } while (current_value && std::cin);

    if (!std::cin) {
        std::cout << "Error, Incorrect input" << std::endl;
    }

    std::cout << "Number of local minimums: " << countMin << std::endl;
    std::cout << "Number of characters changed: " << countChanges << std::endl;
}
