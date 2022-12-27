#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <ctime>
#include "maxCountOfEqualElements.h"
#include "samePositiveElements.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "Erorr!";
    return 1;
  }
  const size_t constSize = 7;
  int constArr[constSize]{ 1, 2, 2, 2, 12, 5, 8 };
  size_t count = 0;
  size_t maxCount = 0;
  std::string ansTrue = "Array has the same positive elements";
  std::string ansFalse = "Array hasn't the same positive elements";
  bool ans = false;
  countMaxQuantityOfEqualElements(constArr, constSize, count, maxCount);
  isThereTheSamePositiveElements(constArr, constSize, ans);
  std::cout << maxCount << "\n";
  std::cout << (ans ? ansTrue : ansFalse) << "\n";

  size_t dinamicSize = 0;
  std::cin >> dinamicSize;
  int* dinamicArr = new int[dinamicSize];
  srand(time(NULL));
  count = 0;
  maxCount = 0;
  ans = false;
  for (int i = 0; i < dinamicSize; ++i)
  {
    dinamicArr[i] = std::rand();
  }
  countMaxQuantityOfEqualElements(dinamicArr, dinamicSize, count, maxCount);
  isThereTheSamePositiveElements(dinamicArr, dinamicSize, ans);
  std::cout << maxCount << "\n";
  std::cout << (ans ? ansTrue : ansFalse) << "\n";
  delete[] dinamicArr;

  count = 0;
  maxCount = 0;
  ans = false;
  std::ifstream file;
  file.open(argv[1]);
  if (!file.is_open())
  {
    std::cout << "Error when you open file\n";
    return 1;
  }
  else if (file.peek() == EOF)
  {
    std::cout << "File empty\n";
    return 1;
  }
  size_t fileSize = 0;
  file >> fileSize;
  int* fileArr = new int[fileSize];
  for (int i = 0; i < fileSize; i++)
  {
    file >> fileArr[i];
  }
  file.close();
  countMaxQuantityOfEqualElements(fileArr, fileSize, count, maxCount);
  isThereTheSamePositiveElements(fileArr, fileSize, ans);
  std::cout << maxCount << "\n";
  std::cout << (ans ? ansTrue : ansFalse) << "\n";
  delete[] fileArr;

  return 0;
}
