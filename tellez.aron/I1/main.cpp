#include <iostream>
<<<<<<< HEAD
int main()
{
  int n = 0;
  int after = 0;
  int actual = 0;
  int before = 0;
  int first = 1;
  bool sign = 0;
  int counter =0;
  int sum = 0;
  std::cout << "Enter the numbers you want, and to finish enter the sequence, enter a 0. \n"
            << "The program will count the sign changes and find sets of Pythagorean numbers in the sequence (z^2=x^2+y^2) \n";
  do
  {
    std::cin >> n;
    after = n;
    actual = after;
    before = actual;
    if (first == 1)
    {
      if (n > 0)
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
      if ((n >= 0) != sign)
=======
using namespace std;
int main()
{
  int actual = 0;
  int posterior = 0;
  int anterior ;
  int n;
  int suma = 0;
  bool sign ;
  int first = 1;
  int counter = 0;
  cout<<"Enter the numbers you want, and to finish enter the sequence, enter a 0:"<<endl
      <<"The program will count the sign changes and find sets of Pythagorean numbers in the sequence (z^2=x^2+y^2)"<<endl;
  while(cin >> n && n != 0)
  {
    anterior = actual;
    actual = posterior;
    posterior = n;
    if(first == 1)
    {
      if(n > 0)
      {
        sign = 1;
      }
      else
      {
        sign = 0;
      }
        first = 0;
      }
    else
    {
      if((n > 0)!=sign)
>>>>>>> master
      {
        sign = !sign;
        counter++;
      }
    }
<<<<<<< HEAD
    if (before == 0 && actual == 0)
=======
 if(anterior == 0 && actual == 0)
>>>>>>> master
    {
      continue;
    }
    else
    {
<<<<<<< HEAD
      if (before * before == actual * actual + after * after)
      {
        sum++;
      }
    }
  }
  while (std::cin  && n);
  std::cout << "Pythagorean numbers found: " << sum;
  std::cout << "\nChange of signs: " << counter << "\n";
=======
      if(anterior * anterior == actual * actual + posterior * posterior)
      {
        suma++;
      }
    }
  }
  cout<<"Pythagorean numbers found: "<<suma<<endl
      <<"Change of signs: "<<counter<<endl;
>>>>>>> master
  return 0;
}
