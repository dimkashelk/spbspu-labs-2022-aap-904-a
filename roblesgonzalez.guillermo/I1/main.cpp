#include <iostream>
#include <limits>
int main()
{
  int n;
  int numberafter = 0;
  int currentnumber = 0;
  int numberbefore = 0;
  int sum = 0;
  int small = std::numeric_limits<int>::max();
  int possiblesmallest = std::numeric_limits<int>::max();
  int counter = 0;

  while(n != 0)
  {
   std::cin>>n;
   numberbefore = currentnumber;
   currentnumber = numberafter;
   numberafter = n;

   if(numberafter == 0)
   {
    continue;
   }
   else
    {
     if((currentnumber < numberbefore) && (currentnumber > numberafter))
     {
      sum++;
     }
    }
   if(counter == 0)
    {
     counter++;
     continue;
    }
   else
     {
      if(n < possiblesmallest)
      {
       if(possiblesmallest == std::numeric_limits<int>::max())
       {
        possiblesmallest = n;
       }
      else
       {
        small = possiblesmallest;
        possiblesmallest = n;
       }
      }
      else
       {
        small = possiblesmallest;
       }
     }
   }
  std::cout<<"Amount of numbers that are smaller than the previous one but bigger than the last one: "<<sum<<std::endl;
  std::cout<<"The smallest number (Excluding first and last number): "<< small<<std::endl;
  return 0;
}
