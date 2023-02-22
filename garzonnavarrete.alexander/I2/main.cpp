#include <iostream>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include "countAriNum.h"
#include "countIndices.h"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cout << "Incorrect number of parameters";
    return 1;
  }
  int arr1[] = {1, 3, 6, 7, 9, 7, 14};
  try
  {
    cout << countAriNum(arr1, 7) << "\n";
    cout << countIndices(arr1, 7) << "\n";
  }
  catch (const std::runtime_error &e)
  {
    cout << e.what();
    return 2;
  }
  size_t n = 0;
  cin >> n;
  int *arr2 = new int[n];
  srand(time(nullptr));
  for (size_t i = 0; i < n; i++)
  {
    arr2[i] = rand();
  }
  try
  {
    cout << countAriNum(arr2, n) << "\n";
    cout << countIndices(arr2, n) << "\n";
  }
  catch (...)
  {
    cout << "0\n";
  }
  delete[] arr2;
  ifstream in(argv[1]);
  if (!in.is_open())
  {
    cout << "Error while opening file\n";
    return 1;
  }
  size_t size = 0;
  in >> size;
  if (!in)
  {
    cout << "Error reading file\n";
    return 1;
  }
  int *arr = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    in >> arr[i];
    if (!in)
    {
      cout << "Error reading file\n";
      delete[] arr;
      return 1;
    }
  }
  try
  {
    cout << countAriNum(arr, size) << "\n";
    cout << countIndices(arr, size) << "\n";
  }
  catch (...)
  {
    cout << "0\n";
  }
  delete[] arr;
  return 0;
}
