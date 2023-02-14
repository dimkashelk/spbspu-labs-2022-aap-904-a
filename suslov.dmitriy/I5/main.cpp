#include <iostream>

int main()
{
  char arr[40];
  std::cin >> arr;
  int c = 0;
  std::cout << std::boolalpha << real(arr, c) << "\n";
  std::cout << c << "\n";
  return 0;
}
