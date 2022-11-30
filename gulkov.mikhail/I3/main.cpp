#include <iostream>
#include "MakeCstring.hpp"
#include "SumStrings.hpp"
#include "GetUniqueSymbols.hpp"

int main()
{
  size_t size_one = 0;
  size_t size_two = 0;
  size_t capacity_one = 10;
  size_t capacity_two = 10;

  char *cstring_one = new char[capacity_one];
  char *cstring_two = new char[capacity_two];

  try
  {
    cstring_one = make_cstring(cstring_one, size_one, capacity_one, std::cin);
    cstring_one[capacity_one - 1] = '\0';
    cstring_two = make_cstring(cstring_two, size_two, capacity_two, std::cin);
    cstring_two[capacity_two - 1] = '\0';
  }
  catch (const std::runtime_error &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    std::cout << "Error: ";
    std::cout << e.what();
    return 2;
  }

  //12

  size_t target_length = (size_one - 1) + (size_two - 1) + 1;
  size_t size_sum = 0;
  size_t capacity_sum = 10;
  char *arr_sum = new char[capacity_sum];
  try
  {
    sum_strings(arr_sum, size_sum, capacity_sum, target_length, cstring_one, size_one, cstring_two, size_two);
  }
  catch (const std::overflow_error &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    delete[] arr_sum;
    std::cout << "Error: ";
    std::cout << e.what();
    return 1;
  }
  std::cout << "Chess sum string: " << arr_sum << "\n";

  //5

  size_t size_unique = 0;
  size_t capacity_unique = 5;
  char *arr_unique = new char[capacity_unique];

  try
  {
    arr_unique = get_unique_symbols(arr_unique, size_unique, capacity_unique, cstring_one, size_one, cstring_two,
                                    size_two);
  }
  catch (const std::overflow_error &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    delete[] arr_sum;
    delete[] arr_unique;
    std::cout << "Error: ";
    std::cout << e.what();
    return 1;
  }
  catch (const std::runtime_error &e)
  {
    delete[] cstring_one;
    delete[] cstring_two;
    delete[] arr_sum;
    delete[] arr_unique;
    std::cout << "Error: ";
    std::cout << e.what();
    return 2;
  }

  std::cout << "Unique symbols sum string: " << arr_unique << "\n";

  //

  delete[] cstring_one;
  delete[] cstring_two;
  delete[] arr_sum;
  delete[] arr_unique;
}
