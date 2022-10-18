#include <iostream>
#include <limits>

struct Counter
{
    Counter(int i) : count(i)
    {
    }
    void operator()(int previous, int current, int next)
    {
      if (previous < current and current < next)
      {
        if (count == max_int)
        {
          throw std::overflow_error("Too much numbers....");
        }
        else
        {
          count++;
        }
      }
    }
    int count;
    const int max_int = std::numeric_limits< int >::max();
};

int main()
{
  Counter counter(0);
  int previous = 0;
  int current = 0;
  int next = 0;
  std::cin >> next;
  previous = current = next;
  while (next && std::cin)
  {
    if (std::cin)
    {
      counter(previous, current, next);
    }
    previous = current;
    current = next;
    std::cin >> next;
  }
  if (!std::cin)
  {
    std::cout << "Error... =(";
    return -1;
  }
  std::cout << counter.count << std::endl;
  return 0;
}