#ifndef COMPUTE_H
#define COMPUTE_H
namespace turkin
{
  struct CompareNums
  {
    int operator()(int last, int current, int amount);
  };
  int isSame(int last, int current, int amount);
}
#endif

