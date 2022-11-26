#include <iostream>
#include "sequences.h"

int main()
{
  int previous = 0;
  Localminimals Localminimals(previous);
  Minsrmax Minsrmax(previous);
  do
  {
    std::cin >> previous;
    if (!std::cin)
    {
      std::cout << "Not a number";
      return 1;
    }
    try
    {
      Localminimals(previous);
      Minsrmax(previous);
    }
    catch (const std::overflow_error & e)
    {
      std::cout << e.what() << "\n";
      return 2;
    }
  }
  while (previous && std::cin);
  std::cout << Localminimals.totalcount() << '\n';
  std::cout << Minsrmax.totalcount() << '\n';
  return 0;
}
