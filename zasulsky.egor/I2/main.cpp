#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include "array.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cout << "Incorrect arguments\n";
    return 1;
  }
  constexpr size_t initSize = 8;
  int initArr[initSize] = {1, -3, 235, -346, 312, 2575, 1239, 234};
  try {
    std::cout << zasulsky::countDescendingThrees(initArr, initSize) << '\n';
    std::cout << *zasulsky::findEvenMax(initArr, initSize) << '\n';
  } catch (const std::invalid_argument& err) {
    std::cout << err.what() << '\n';
  } catch (const std::exception& err) {
    std::cout << err.what() << '\n';
    return 1;
  }

  std::srand(std::time(NULL));
  size_t dynSize = 0;
  std::cin >> dynSize;
  if (!std::cin) {
    std::cout << "Input error\n";
    return 1;
  }
  int* dynArr = new int[dynSize];
  for (size_t i = 0; i < dynSize; i++) {
    dynArr[i] = std::rand();
  }
  try {
    std::cout << zasulsky::countDescendingThrees(dynArr, dynSize) << '\n';
    std::cout << *zasulsky::findEvenMax(dynArr, dynSize) << '\n';
  } catch (const std::invalid_argument& err) {
    std::cout << err.what() << '\n';
  } catch (const std::exception& err) {
    std::cout << err.what() << '\n';
    delete [] dynArr;
    return 1;
  }
  delete [] dynArr;

  std::fstream file(argv[1]);
  if (!file.is_open()) {
    std::cout << "Can't open file\n";
    return 1;
  }
  size_t fileSize = 0;
  file >> fileSize;
  if (!file) {
    std::cout << "Input error\n";
    return 1;
  }
  int* fileArr = new int[fileSize];
  for (size_t i = 0; i < fileSize; i++) {
    file >> fileArr[i];
    if (!file) {
      std::cout << "Input error\n";
      delete [] fileArr;
      return 1;
    }
  }
  try {
    std::cout << zasulsky::countDescendingThrees(fileArr, fileSize) << '\n';
    std::cout << *zasulsky::findEvenMax(fileArr, fileSize) << '\n';
  } catch (const std::invalid_argument& err) {
    std::cout << err.what() << '\n';
  } catch (const std::exception& err) {
    std::cout << err.what() << '\n';
    delete [] fileArr;
    return 1;
  }
  delete [] fileArr;
}
