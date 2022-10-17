#include <iostream>
struct Counter
{
    Counter(int i) : count(i)
    {
    }
    void operator()(int previous, int current, int next)
    {
      if (previous < current and current < next)
      {
        count++;
      }
    }
    int count;
};
int main()
{

}