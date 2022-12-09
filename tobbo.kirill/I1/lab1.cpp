#include <iostream>

const char* ERROR_INVALID_INPUT = "Error:input must only contain integers.";

int main() {
  int countMax = 0;
  int countLocalMax = 0;
  int maxx = INT_MIN;
  int third = 0;
  int first = 0;
  int second = 0;
  std::cout << "Enter numbers:" << std::endl;
  try {
    do {
      std::cin >> third;
      if (std::cin.fail())
        throw ERROR_INVALID_INPUT;

      if (third != 0) {
        if (third > maxx) {
          countMax = 0;
          maxx = third;
        }
        if (third == maxx)
          countMax++;
        if (first < second && second > third)
          countLocalMax++;
        first = second;
        second = third;
      }
    }
    while (third != 0);

    if (countMax == 0)
      std::cout << "The sequence is empty." << std::endl;
    else {
      std::cout << "Count of maximum values: " << countMax << " Max value: " << maxx << std::endl;
      std::cout << "Count of local maximums: " << countLocalMax << std::endl;
    }
  }

  catch(const char *error) {
    std::cerr << std::endl << error << std::endl;
  }
}
