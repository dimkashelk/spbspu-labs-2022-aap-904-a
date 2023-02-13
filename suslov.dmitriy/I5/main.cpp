#include <iostream>

int main()
{
  char arr[40];
  std::cin >> arr;
  int c = 0;
  std::cout << std::boolalpha << real(arr, c) << std::endl;
  std::cout << c << std::endl;
  return 0;
}
