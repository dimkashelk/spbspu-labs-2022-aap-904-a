#include <iostream>
#include <limits>
int main()
{
  int n;
  int nafter = 0;
  int currentn = 0;
  int nbefore = 0;
  int sum = 0;
  double smalln = std::numeric_limits<double>::infinity();
  double possiblesmallest = std::numeric_limits<double>::infinity();
  int counter = 0;
  while(n != 0)
  {
   std::cin>>n;
   nbefore = currentn;
   currentn = nafter;
   nafter = n;

   if(nafter == 0)
   {
    continue;
   }
   else
    {
     if((currentn < nbefore) && (currentn > nafter))
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
       if(possiblesmallest == std::numeric_limits<double>::infinity())
       {
        possiblesmallest = n;
       }
      else
       {
        smalln = possiblesmallest;
        possiblesmallest = n;
       }
      }
      else
       {
        smalln = possiblesmallest;
       }
     }
   }
  std::cout << "Amount of numbers that are smaller than the previous one but bigger:  "<<sum<<std::endl;
  std::cout << "The smallest number (Excluding first and last):  "<< small<<std::endl;
  return 0;
}
