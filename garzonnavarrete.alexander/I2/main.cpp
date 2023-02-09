#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
  int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20};
  int max = INT_MIN;
  int min = INT_MAX;
  int imin = 0, imax = 0, suma = 0;
  double avg = 0.0;

  for (size_t i = 0; i < 18; ++i) {
    if (arr[i] < min) {
      min = arr[i];
      imin = i;
    }
    if (arr[i] > max) {
      max = arr[i];
      imax = i;
    }
  }
  suma = imin + imax;
  for (size_t i = 0; i < 18; i+=2) {
    avg += arr[i];
  }
  avg /= 9;
  
    std::cout << "The min element is: " << min << std::endl;
    std::cout << "The max element is: " << max << std::endl;
    std::cout << "The sum of indices of the max and min is: " << suma << std::endl;
    std::cout << "The average of elements at even indices is: " << avg <<std::endl;
  return 0;
}
