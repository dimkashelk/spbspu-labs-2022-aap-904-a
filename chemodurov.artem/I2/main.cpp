#include "numbers.h"
#include <iostream>
#include <fstream>
#include <cmath>

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cerr << "Not correct amolunt of CML args\n";
    return 2;
  }

  int divider = 3;
  std::ifstream input(argv[1]);
  if (!input)
  {
    std::cerr << argv[1] << " Error while reading\n";
    return 2;
  }
  size_t arr_size = 5;
  size_t new_arr_size = 5;
  int * arr = new int[arr_size];
  int * new_arr = nullptr;
  for (size_t i = 0; i < arr_size; ++i)
  {
    int x = 0;
    input >> x;
    if (!input)
    {
      std::cerr << argv[1] << " Error while reading\n";
      return 2;
    }
    arr[i] = x;
    if (i == arr_size - 1)
    {
      new_arr_size = ceil(sqrt(2) * arr_size);
      new_arr = chemodurov::extendDynArray(arr, arr_size, new_arr_size);
      delete [] arr;
      arr = new_arr;
      new_arr = nullptr;
      arr_size = new_arr_size;
    }
    input >> std::ws;
    if (input.eof())
    {
      ++i;
    }
  }
  unsigned int arr_cnt_dec = chemodurov::countMaxDecreasing(arr, arr_size);
  unsigned int arr_cnt_div = chemodurov::countDivisible(arr, arr_size, divider);
  std::cout << arr_cnt_dec << " " << arr_cnt_div << "\n";
  delete [] arr;
  size_t n = 0;
  std::cin >> n;
  if (!std::cin)
  {
    std::cerr << "Error...\n";
    return 1;
  }
  if (n > 0)
  {
    int * dyn_arr = new int[n];
    for (size_t i = 0; i < n; ++i)
    {
      dyn_arr[i] = rand();
    }
    unsigned int dyn_a_cnt_dec = chemodurov::countMaxDecreasing(dyn_arr, n);
    unsigned int dyn_a_cnt_div = chemodurov::countDivisible(dyn_arr, n, divider);
    delete [] dyn_arr;
    std::cout << dyn_a_cnt_dec << " " << dyn_a_cnt_div << "\n";
  }
  else
  {
    std::cout << "0 0\n";
  }

  int a[10] = {3,2,1,7,5,4,2,9,8,4};
  int * a_ptr = &a[0];
  size_t a_size = 10;
  unsigned int a_cnt_dec = chemodurov::countMaxDecreasing(a_ptr, a_size);
  unsigned int a_cnt_div = chemodurov::countDivisible(a_ptr, a_size, divider);
  std::cout << a_cnt_dec << " " << a_cnt_div << "\n";
  return 0;
}
