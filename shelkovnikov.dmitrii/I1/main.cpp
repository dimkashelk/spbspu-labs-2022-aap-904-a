#include <iostream>
#include <limits>

class Counter
{
public:
    Counter(int i) :
      count(i)
    {
    }
    void operator()(int previous, int current, int next)
    {
      if (previous < current && current < next)
      {
        if (count == max_int)
        {
          throw std::overflow_error("Too much numbers....");
        } else
        {
          count++;
        }
      }
    }
    int get_count()
    {
      return count;
    }
private:
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
  try
  {
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
