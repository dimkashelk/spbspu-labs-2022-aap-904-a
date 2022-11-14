#include "dynamicArray.h"
#include "downSequence.h"
#include "repeatedNums.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "invalid amount of arguments\n";
    return 1;
  }

  std::string filename = argv[1];
  size_t basicCapacity = 5;
  const size_t constSize = 10;
  size_t dynamicSize = 0;
  size_t fileSize = 0;
  int constArray[constSize] = {4, 3, 2, 1, 5, 2, 1, 9, 9, 9};
  turkin::Array * dynamicArray = new turkin::Array(basicCapacity);
  turkin::Array * fileArray = new turkin::Array(basicCapacity);

  std::cin >> dynamicSize;
  if (!std::cin)
  {
    std::cerr << "incorrect input\n";
    return 2;
  }
  for (size_t i = 0; i < dynamicSize; i++)
  {
    if (dynamicArray->size + 1 > dynamicArray->capacity)
    {
      try
      {
        dynamicArray->capacity = dynamicArray->capacity + 10;
        dynamicArray->data = turkin::extend(dynamicArray->data, dynamicArray->size, dynamicArray->capacity + 10);
      }
      catch (std::invalid_argument & error)
      {
        std::cout << error.what();
        return 5;
      }
    }
    dynamicArray->size++;
    dynamicArray->data[i] = std::rand() % 10;
  }

  std::fstream input(filename);
  std::string line;
  if (!input.is_open())
  {
    std::cerr << "cannot open file\n";
    return 3;
  }
  try
  {
    getline(input, line);
    fileSize = std::stoi(line);
  }
  catch (std::invalid_argument & error)
  {
    std::cout << error.what() << "\t" << "<empty file>";
    return 6;
  }
  for (size_t i = 0; i < fileSize; i++)
  {
    if (fileArray->size + 1 > fileArray->capacity)
    {
      try
      {
        fileArray->capacity = fileArray->capacity + 10;
        fileArray->data = turkin::extend(fileArray->data, fileArray->size, fileArray->capacity + 10);
      }
      catch (std::invalid_argument & error)
      {
        std::cout << error.what();
        return 5;
      }
    }
    getline(input, line);
    fileArray->size++;
    fileArray->data[i] = std::stoi(line);
  }

  turkin::DownSequence downSequence;
  turkin::RepeatedNums repeatedNums;
  size_t constSequence = downSequence(constArray, constSize);
  size_t dynamicSequence = downSequence(dynamicArray->data, dynamicArray->size);
  size_t fileSequence = downSequence(fileArray->data, fileArray->size);
  try
  {
    bool constRepeated = repeatedNums(constArray,
                                        constSize,
                                        0,
                                        constSize);
    bool dynamicRepeated = repeatedNums(dynamicArray->data,
                                          dynamicArray->size,
                                          0,
                                          dynamicArray->size);
    bool fileRepeated = repeatedNums(fileArray->data,
                                       fileArray->size,
                                       0,
                                       fileArray->size);
    std::cout << constSequence << "\t" << dynamicSequence << "\t" << fileSequence << "\n";
    std::cout << constRepeated << "\t" << dynamicRepeated << "\t" << fileRepeated << "\n";
  }
  catch (std::invalid_argument & error)
  {
    std::cout << error.what() << std::endl;
    delete dynamicArray;
    delete fileArray;
    return 4;
  }
  delete dynamicArray;
  delete fileArray;
  return 0;
}
