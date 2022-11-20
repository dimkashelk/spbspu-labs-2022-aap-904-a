#include <iostream>
#include "PifTrio.hpp"
#include "ChangeSignCounter.hpp"

int main()
{
  FindPifTrio pif_trio{0};
  CountSignChanges sign_changes{0};
  int x, y = 0, z = 0;
  for (;;)
  {
    std::cin >> x;
    if (std::cin.fail())
    {
      std::cout << "Illegal character";
      break;
    }
    if (x == 0)
    {
    break;
    }
    try
    {
      if (x != 0 && y != 0 && z != 0)
      {
        pif_trio(x, y, z);
      }
      if (x !=0 && y != 0)
      {
        sign_changes(x, y);
      }
    }
    catch(const std::overflow_error& error)
    {
      std::cout << "Error: " << error.what() << "\n";
      return 1;
    }
    z = y;
    y = x;
  }
  if (!std::cin.fail())
  {
    std::cout << "Count of Pythogorean triplets " << pif_trio.PifCounter << "\n";
    std::cout << "Count of number sign changes " << sign_changes.ChangeSignCounter << "\n";
  }
}
