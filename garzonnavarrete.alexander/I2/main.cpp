#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
  int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20};
  int max = INT_MIN;
  int min = INT_MAX;
  int suma = INT_MAX + INT_MIN;
  double sum = 0.0;

  for (int i: arr) {
    if (i < min) {
      min = i;
    }
    if (i > max) {
      max = i;
    }
    if (i) {
      suma = min + max;
    }
  }
  for (size_t i = 0; i < 18; i+=2) {
    sum += arr[i];
  }
    cout << "The min element is: " << min << endl;
    cout << "The max element is: " << max << endl;
    cout << "The sum between max and min is: " << suma << endl;
    cout << "The arithmetic media is: " << sum / ((18 + 1)/2) << endl;

  return 0;
}
