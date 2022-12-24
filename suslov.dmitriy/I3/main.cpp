#include <iostream>
#include "formNewStringVarFiveteen.h"
#include <fstream>
#include "formNewStringVarFive.h"
int main(int argc, char **argv)
{
  if(argc<3)
  {
    return 0;
  }
  std::ifstream in_stream;
  std::ofstream out_stream;
  in_stream.open(argv[1]);
  if (!in_stream.is_open())
  {
    std::cerr << "=(" << "\n";
    return 1;
  }
  out_stream.open(argv[2]);
  if (!out_stream.is_open())
  {
    std::cerr << "=(" << "\n";
    return 2;
  }
  while (!in_stream.fail())
  {
    std::string string_first;
    std::string string_second;
    in_stream >> string_first >> string_second;
    char *result1;
    try
    {
      result1 = new char[string_first.size() + string_second.size() + 1];
    } catch (std::bad_alloc &e)
    {
      std::cerr << "Fail" << "\n";
      return 3;
    }
    out_stream << varFiveFunction(result1, string_first.c_str(), string_second.c_str()) << "\n";
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
    out_stream << varFiveteenFunction(result2, string_first.c_str(), string_second.c_str()) << "\n";
    delete[] result2;
  }
  return 0;
}
