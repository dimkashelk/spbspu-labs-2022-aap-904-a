#include <iostream>
#include "formNewStringVarFiveteen.h"
#include <fstream>
#include "formNewStringVarFive.h"
//int main(int argc, char **argv)
//{
//  if (argc < 2)
//  {
//    std::cout << "Zero exit code without error message in standard error and some output" << "\n";
//    return 0;
//  }
//  if (argc < 3)
//  {
//    std::cout << "Non-zero exit code with error message in standard error" << "\n";
//    return 0;
//  }
//  std::ifstream in_stream;
//  std::ofstream out_stream;
//  in_stream.open(argv[1]);
//  if (in_stream.eof())
//  {
//    std::cout << "Non-zero exit code with error message in standard error" << "\n";
//    return 0;
//  }
//  in_stream.open(argv[1]);
//  if (!in_stream.is_open())
//  {
//    std::cerr << "=(" << "\n";
//    return 1;
//  }
//  out_stream.open(argv[2]);
//  if (!out_stream.is_open())
//  {
//    std::cerr << "=(" << "\n";
//    return 2;
//  }
//  while (!in_stream.fail())
//  {
//    std::string string_first;
//    std::string string_second;
//    in_stream >> string_first >> string_second;
//    char *result1;
//    try
//    {
//      result1 = new char[string_first.size() + string_second.size() + 1];
//    } catch (std::bad_alloc &e)
//    {
//      std::cerr << "Fail" << "\n";
//      return 3;
//    }
//    out_stream << varFiveFunction(result1, string_first.c_str(), string_second.c_str()) << "\n";
//    delete[] result1;
//    char *result2;
//    try
//    {
//      result2 = new char[string_first.size() + 1];
//    } catch (std::bad_alloc &e)
//    {
//      std::cerr << "Fail" << "\n";
//      return 3;
//    }
//    out_stream << varFiveteenFunction(result2, string_first.c_str(), string_second.c_str()) << "\n";
//    delete[] result2;
//  }
//  return 0;
//}

int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  } while (std::cin && cstring[size++] != '\n');
  cstring[size - 1] = '\0';
  if (size == 0 or size == 1)
  {
    std::cerr << "Empty input" << '\n';
    delete[] cstring;
    return -1;
  }
  std::cout << cstring << "\n";
  delete[] cstring;
}