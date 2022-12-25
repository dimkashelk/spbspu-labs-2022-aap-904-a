#include <iostream>
#include "ArrayOperations.h"

int main()
{
  int arr[] = {0, 1, 2, 3, 4, 5, 6};
  int n = 0;
  int m = 0;

  std::cin >> n >> m;
  shiftByIndexes(arr, 7, n, m);
  std::cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << arr[5] << arr[6] << " <-done\n";
}
