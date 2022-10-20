#include <iostream>
#include <limits>

class Counter
{
public:
    Counter() :
      count(0)
    {}
    Counter(int prev, int cur) :
      previous(prev),
      current(cur),
      count(0)
    {}
    void operator()(int next)
    {
      if (previous < current && current < next)
      {
        if (count == max_int)
        {
          throw std::overflow_error("Too much numbers....");
        }
        else
        {
          count++;
        }
        previous = current;
        current = next;
      }
    }
    int get_count()
    {
      return count;
    }
private:
    int count = 0;
    int previous = 0;
    int current = 0;
    const int max_int = std::numeric_limits< int >::max();
};

int main()
{
  int next = 0;
  std::cin >> next;
  Counter counter(next, next);
  try
  {
    while (next && std::cin)
    {
      if (std::cin)
      {
        counter(next);
      }
      std::cin >> next;
    }
  }
  catch (std::overflow_error &e)
  {
    std::cout << e.what();
    return -1;
  }
  if (!std::cin)
  {
    std::cout << "Error... =(";
    return -1;
  }
  std::cout << counter.get_count() << std::endl;
  return 0;
}
