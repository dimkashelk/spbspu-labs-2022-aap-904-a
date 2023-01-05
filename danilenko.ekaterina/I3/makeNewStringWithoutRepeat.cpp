#include <iostream>

int main() 
{
  const size_t size = 10;
  char str1[size], str2[size];
  std::cout << "Enter first string: ";
  std::cin >> str1;
  std::cout << "Enter second string: ";
  std::cin >> str2;
 
  std::cout << "New string with uncommon elements: ";

  for (size_t i = 0; i < size; i++) 
  {
    for (size_t j = 0; j < size; j++)
    {
      if (str1[i] == str2[j])
      {
        break;
      }
      else if (j == size - 1) 
      {
        std::cout << str1[i];
        break;
      }
    }
  }

  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if (str2[i] == str1[j])
      {
        break;
      }
      else if (j == size - 1) 
      {
        std::cout << str2[i];
        break;
      }
    }
  }
  return 0;
}