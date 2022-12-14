#include <iostream>
#include "15var.h"
#include <fstream>
#include "5var.h"
int main()
{
  //std::ifstream in;
  //std::ofstream out;
  //in.open("in.txt");
  //if (!in.is_open())
  //{
  //  std::cerr << "=(" << "\n";
  //  return 1;
  //}
  //out.open("out.txt");
  //if (!out.is_open())
  //{
  //  std::cerr << "=(" << "\n";
  //  return 2;
  //}
  while (!std::cin.fail())
  {
    std::string string_first;
    std::string string_second;
    std::cin >> string_first >> string_second;
    char *result1;
    try
    {
      result1 = new char[string_first.size() + string_second.size() + 1];
    } catch (std::bad_alloc &e)
    {
      std::cerr << "Fail" << "\n";
      return 3;
    }
    std::cout << var_5_function(result1, string_first.c_str(), string_second.c_str()) << "\n";
    delete[] result1;
    char *result2;
    try
    {
      result2 = new char[string_first.size() + 1];
    } catch (std::bad_alloc &e)
    {
      std::cerr << "Fail" << "\n";
      return 3;
    }
    std::cout << var_15_function(result2, string_first.c_str(), string_second.c_str()) << "\n";
    delete[] result2;
  }
  return 0;
}
