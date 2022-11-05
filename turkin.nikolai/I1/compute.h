#ifndef COMPUTE_H
#define COMPUTE_H
namespace turkin
{
  struct LengthOfSequence
  {
    void updateAmount(int last, int current);
    int isSame(int last, int current);
    int getMaxAmount();

    int currentAmount = 0;
    int maxAmount = 0;
    int count = 0;
  };

  struct PreMaximum
  {
    void updatePreMaximum(int current);
    int getPreMaximum();
    int allMax = 0;
    int beforeMax = 0;
  };
}
#endif
