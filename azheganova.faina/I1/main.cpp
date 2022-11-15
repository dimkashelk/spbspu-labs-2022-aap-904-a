#include <iostream>
struct Localminimals
{
  void operator()(int previous, std::istream& in)
  {
    if (in)
	{
	  if ((current < previous) && (current < next))
	  {
	    countlocalmin++;
	  }
	  next = current;
	  current = previous;
    }
  }
  int countlocalmin;
  int current;
  int next;
};
struct Minsrmax
{
  void operator()(int previous, std::istream& in)
  {
    if (in)
    {
	  i++;
	  if ((i>2) && (current < previous) && (current > next))
	  {
	    countminsrmax++;
	  }
	  next = current;
	  current = previous;
    }
  }
  int i = 0;
  int countminsrmax;
  int current;
  int next;
};
int main()
{
  int previous;
  Localminimals count1{0};
  Minsrmax count2{0};
  do
  {
    std::cin >> previous;
    count1(previous, std::cin);
    count2(previous, std::cin);
  } 
  while (previous && std::cin);
  if (!std::cin)
  {
    std::cout << "Not a number";
  }
  std::cout << count1.countlocalmin << '\n';
  std::cout << count2.countminsrmax << '\n';
}
