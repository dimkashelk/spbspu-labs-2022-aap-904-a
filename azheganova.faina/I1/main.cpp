#include <iostream>
#include "sequences.h"

int main()
{
  int previous = 0;
  Localminimals localminimals(previous);
  Minsrmax minsrmax (previous);
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
      localminimals(previous);
      minsrmax(previous);
    }
    catch (const std::overflow_error & e)
    {
      std::cout << e.what() << "\n";
      return 2;
    }
  }
  while (previous && std::cin);
  std::cout << localminimals.generalcount() << '\n';
  std::cout << minsrmax.generalcount() << '\n';
  return 0;
}
