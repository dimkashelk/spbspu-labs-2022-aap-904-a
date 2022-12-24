#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"

using std::cout;
using std::cin;

const int N = 10;
const int randMin = -50;
const int randMax = 50;

int main()
{
  srand(time(0));
  
  int k;
  if (!inputInteger("Enter number of elements for shift: ", k)) {
    return 1;
  }
  
  const int N = 10;
  int staticArray[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << "Static array: ";
  processArray(staticArray, N, k);
  
  int n;
  if (!inputInteger("Enter number of elements in dynamic array: ", n)) {
    return 1;
  }
  int *dynamicArray = new int[n];
  for (int i = 0; i < n; i++) {
    dynamicArray[i] = rand() % (randMax - randMin + 1) + randMin;
  }
  processArray(dynamicArray, n, k);
  delete [] dynamicArray;
  
  int numberOfArrays;
  if (!inputInteger("Enter number of files with arrays: ", numberOfArrays)) {
    return 1;
  }
  for (int i = 0; i < numberOfArrays; i++) {
    std::string filename;
    cout << "Enter filename: ";
    cin >> filename;
    if (!inputArray(filename, dynamicArray, n)) {
      cout << "Can't open the file or read the array\n";
      return 1;
    }
    processArray(dynamicArray, n, k);
    delete [] dynamicArray;
  }
  return 0;
}
