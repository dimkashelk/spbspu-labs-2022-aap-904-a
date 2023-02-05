#include "inputStr.h"

void inputStr(size_t& size, char*& str)
{
  if (!(std::cin >> size))
  {
    std::cerr << "Input error\n";
  }
  try
  {
    str = new char[size + 1];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }
  if (!(std::cin >> str))
  {
    std::cerr << "Input error\n";
  }
}
