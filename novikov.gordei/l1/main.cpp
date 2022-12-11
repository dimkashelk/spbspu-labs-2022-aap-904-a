#include <iostream>
#include "checkPythagoreanTriples.h"

int main()
{
  int numbOfPythagoreanTriples = 0;
  long x = 0, y = 0, z = 1, max1 = 0, max2 = 0;
  int k = 0;

  while (z != 0) {
    std::cin >> z;
    if (std::cin.fail()) {
      std::cout << "The element of the sequence is not a integer number" << std::endl;
      return 1;
    }
    k++;
    if (k == 1) {
      if (z == 0) {
        std::cout << "The sequence is empty" << std::endl;
        return 1;
      }
      x = z;
      max1 = x;
      continue;
    }
    if (k == 2) {
      if (z == 0) {
        std::cout << "The sequence contains less than 2 elements" << std::endl;
        return 1;
      }
      y = z;
      if (y >= max1) {
        max2 = max1;
        max1 = y;
      }
      else if (y >= max2) {
        max2 = y;
      }
      continue;
    }

    if (z >= max1) {
      max2 = max1;
      max1 = z;
    }
    else if (z >= max2) {
      max2 = z;
    }

    if (isPythagoreanTriples(x, y, z)) numbOfPythagoreanTriples++;
    x = y;
    y = z;

  }
  std::cout << "The value of the second largest element is " << max2 << std::endl;
  if (k <= 3) {
    std::cout << "The sequence contains less than 3 elements" << std::endl;
  }
  else {
    std::cout << "The number of Pythagorean triples is " << numbOfPythagoreanTriples << std::endl;
  }

  return 0;
}
