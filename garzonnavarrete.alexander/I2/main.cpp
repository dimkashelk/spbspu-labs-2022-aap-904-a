#include <iostream>
#include <fstream>
#include <climits>
#include <ctime>
using namespace std;

void process_array(int* arr, int n) {
  int max = INT_MIN;
  int min = INT_MAX;
  int imin = 0, imax = 0, suma = 0;
  double avg = 0.0;
  for (size_t i = 0; i < n; ++i) {
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
  int c = 0;
  for (size_t i = 0; i < n; i+=2) {
    avg += arr[i];
    ++c;
  }
  avg /= c;
  std::cout << "The min element is: " << min << std::endl;
  std::cout << "The max element is: " << max << std::endl;
  std::cout << "The sum of indices of the max and min is: " << suma << std::endl;
  std::cout << "The average of elements at even indices is: " << avg <<std::endl;
}
int main(int argc, char** argv)
{
  srand(time(NULL));
  int arr1[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20};
  process_array(&(arr1[0]), 18);
  size_t n;
  cin >> n;
  if (n <= 0) {
    std::cerr << "Invalid array length." << endl;
    return -1;
  }
  int* arr2 = new int[n];
  for(size_t i = 0; i < n; ++i) arr2[i] = rand();
  process_array(arr2, n);
  delete[] arr2;
  if (argc > 0) {
    ifstream ifs;
    ifs.open(argv[1]);
    if (ifs) {
      ifs >> n;
      if (n <= 0) {
        std::cerr << "Invalid array length specified in the file." << endl;
        return -2;
        }
      int* arr3 = new int[n];
      for(size_t i = 0; i < n; ++i) ifs >> arr3[i];
      process_array(arr3, n);
      delete[] arr3;
      }
  }
  else
  {
    std::cerr << "No input file." << endl;
  }
  return 0;
}
