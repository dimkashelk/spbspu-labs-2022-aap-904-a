#include <iostream>
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
      {
        sign = !sign;
        counter++;
      }
    }
 if(anterior == 0 && actual == 0)
    {
      continue;
    }
    else
    {
      if(anterior * anterior == actual * actual + posterior * posterior)
      {
        suma++;
      }
    }
  }
  cout<<"Pythagorean numbers found: "<<suma<<endl
      <<"Change of signs: "<<counter<<endl;
  return 0;
}

