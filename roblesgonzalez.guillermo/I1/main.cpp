#include <iostream>
using namespace std;
int main()
{
  int actual = 0;
  int nafter = 0;
  int nbefore;
  int n;
  int sum = 0;
  int small = 10000000;
  int possiblesmall = 10000000;
  int contador = 0;

  while(cin>>n && n != 0)
  {
    nbefore = actual;
    actual = nafter;
    nafter = n;

    if(nafter == 0)
    {
      continue;
    }
      else
      {
        if ((actual < nbefore) && (actual > nafter))
        {
         sum++;
        }
      }
        if(contador == 0)
        {
         contador++;
         continue;
        }
        else
        {
           if(n < possiblesmall)
           {
             if(possiblesmall == 10000000)
             {
               possiblesmall = n;
             }
             else
             {
                small = possiblesmall;
                possiblesmall = n;
             }
           }
             else
             {
                small = possiblesmall;
             }
        }
  }
  cout<<"Amount of numbers that are smaller than the previous one but bigger than the last one: "<<sum<<endl;
  cout<<"The smallest number (Excluding first and last number): "<<small<<endl;
  return 0;
}
