#include "functions.h"
#include <iostream>
#include <fstream>
#include <string>

void shiftArray(int* array, int N, int k)
{
  for (int j = 0; j < k; j++) {
    int tmp = array[N - 1];
    for (int i = N - 1; i > 0; i--) {
      array[i] = array[i - 1];
    }
    array[0] = tmp;
  }
}

int getPositiveAvg(const int* array, int N)
{
  int cnt = 0;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (array[i] > 0) {
      cnt++;
      sum += array[i];
    }
  }
  return cnt ? sum / cnt : 0;
}

void printArray(const int* array, int N)
{
  for (int i = 0; i < N; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

bool inputArray(std::string filename, int*& array, int& N)
{
  std::ifstream file(filename);
  if (!file.is_open()) {
    return false;
  }
  file >> N;
  if (file.fail() || N < 0) {
    file.close();
    return false;
  }
  array = new int[N];
  for (int i = 0; i < N; i++) {
    file >> array[i];
  }
  if (file.fail()) {
    delete[] array;
    file.close();
    return false;
  }
  file.close();
  return true;
}

void processArray(int* array, int N, int k)
{
  if (N == 0) {
    std::cout << "Empty array\n";
    return;
  }
  printArray(array, N);
  std::cout << "After shift: ";
  shiftArray(array, N, k);
  printArray(array, N);
  std::cout << "Positive elements average: " << getPositiveAvg(array, N) << "\n";
}

bool inputInteger(std::string msg, int& n)
{
  std::cout << msg;
  std::cin >> n;
  if (std::cin.fail() || n < 0) {
    std::cout << "Number is not a positive integer\n";
    return false;
  }
  return true;
}
