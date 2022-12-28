#include <iostream>

int main()
{
  double borderleft = 0.0;
  double borderright = 0.0;
  int maxnumber = 0;
  std::cin >> borderleft;
  std::cin >> borderright;
  std::cin >> maxnumber;
  if (!std::cin)
  {
    std::cout << "error";
    return 1;
  }

}