#include <iostream>
#include <fstream>
#include <cstdlib>
#include "dynamicArray.h"
#include "downSequence.h"
#include "repeatedNums.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "invalid amount of arguments" << std::endl;
    return 1;
  }

  const size_t constSize = 10;
  int constArray[constSize] = {4, 3, 2, 1, 5, 2, 1, 9, 9, 9};

  size_t dynamicSize = 0;
  std::cin >> dynamicSize;
  if (!std::cin)
  {
    std::cerr << "incorrect input" << std::endl;
    return 2;
  }
  turkin::Array dynamicArray(dynamicSize);
  for (size_t i = 0; i < dynamicSize; i++)
  {
    dynamicArray.size++;
    dynamicArray.data[i] = std::rand() % 10;
  }

  std::string filename = argv[1];
  std::fstream input(filename);
  size_t fileSize = 0;
  if (!input.is_open())
  {
    std::cerr << "cannot open file" << std::endl;
    return 3;
  }
  if (input.peek() == EOF)
  {
    std::cerr << "empty file" << std::endl;
    return 4;
  }
  input >> fileSize;
  turkin::Array fileArray(fileSize);
  for (size_t i = 0; i < fileSize; i++)
  {
    fileArray.size++;
    input >> fileArray.data[i];
  }
  size_t constSequence = turkin::getDownSequence(constArray, constSize);
  size_t dynamicSequence = turkin::getDownSequence(dynamicArray);
  size_t fileSequence = turkin::getDownSequence(fileArray);
  try
  {
    bool constRepeated = turkin::getRepeatedNums(constArray, constSize, 0, constSize);
    bool dynamicRepeated = turkin::getRepeatedNums(dynamicArray, 0,dynamicArray.size);
    bool fileRepeated = turkin::getRepeatedNums(fileArray, 0, fileArray.size);
    std::cout << constSequence << "\t" << dynamicSequence << "\t" << fileSequence << std::endl;
    std::cout << constRepeated << "\t" << dynamicRepeated << "\t" << fileRepeated << std::endl;
  }
  catch (std::invalid_argument const & error)
  {
    std::cerr << error.what() << std::endl;
    return 5;
  }
  return 0;
}
