#include <iostream>

struct Counter
{
    void operator()(int previous, int current, int next)
    {
      if (previous < current and current < next)
      {
        count++;
      }
    }
    int count = 0;
};

int main()
{
}