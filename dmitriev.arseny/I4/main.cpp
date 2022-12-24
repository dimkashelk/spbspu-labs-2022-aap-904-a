#include <iostream>
#include <cstddef>
#include <fstream>
#include "countLinesNoZero.h"
#include "countMonoIncreaceLines.h"

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cout << "not enough arguments" << '\n';
    return 1;
  }

  std::ofstream fileOut(argv[2]);
  if (!fileOut.is_open())
  {
    std::cout << "problems while opening file" << '\n';
    return 1;
  }

  int matrix[] = { 0, 2, 3, 4, 5, 6 };
  size_t line = 2, column = 3;

  fileOut << countLinesNoZero(matrix, line, column) << '\n';
  fileOut << countMonoIncreaceLines(matrix, line, column) << '\n';

  fileOut.close();

  return 0;
}
