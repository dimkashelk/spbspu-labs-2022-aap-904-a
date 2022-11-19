#include <iostream>
#include "header.h"
int main()
{
  int p2 = 0, p1 = 0;
  unsigned int k = 0;
  unsigned int max_Mono = 0;
  unsigned int max_DelBezOst = 0;
  do
  {
    p1 = p2;
    std::cin >> p2;
  if (!std::cin)
  {
      std::cout << "Inp error" << std::endl;
  }
  if (p2 == 0)
    {
      break;
    }
  try
  {
  max_Mono_foo(max_Mono, k, p1, p2);
  max_DelBezOst_foo(max_DelBezOst, p1, p2);
  }
  catch (std::overflow_error& e)
  {
    std::cout << e.what() << "\n" << std::endl;
    return 1;
  }
  } while (std::cin and p2);


  std::cout << "max mono increace - " << max_Mono << std::endl;
  std::cout << "without remainder divisible by the preceding - " << max_DelBezOst << std::endl;

  return 0;
}
