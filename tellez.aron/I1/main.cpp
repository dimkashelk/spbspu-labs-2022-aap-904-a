#include <iostream>
int main()
{
  int n;
  int before;
  int actual = 0;
  int after;
  int first = 1 ;
  bool sign;
  int counter = 0;
  int sum = 0;
  std::cout << "Enter the numbers you want, and to finish enter the sequence, enter a 0:" <<  std::endl
            << "The program will count the sign changes and find sets of Pythagorean numbers in the sequence (z^2=x^2+y^2)" << std::endl;
  while(std::cin >> n && n != 0)
  {
    before = actual;
    actual = after;
    after = n;
    if(first == 1)
    {
      if(n > 0)
      {
        sign = true;
      }
      else
      {
        sign = false;
      }
        first = 0;
      }
    else
    {
      if((n > 0) != sign)
      {
        sign = !sign;
        counter++;
      }
    }
    if(before == 0 && actual == 0)
    {
      continue;
    }
    else
    {
      if(before * before == actual * actual + after * after || before * before + actual * actual == after * after)
      {
        sum++;
      }
    }
  }
  std::cout << "Pythagorean numbers found: " << sum << std::endl
            << "Change of signs: " << counter << std::endl;
  return 0;
}
