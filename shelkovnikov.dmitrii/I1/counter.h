#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTER_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTER_H
#include <limits>
class Counter
{
public:
    Counter();
    Counter(int prev, int cur);
    void operator()(int next);
    int get_count() const;
private:
    unsigned int count;
    int previous;
    int current;
};

#endif //SPBSPU_LABS_2022_AAP_904_A_COUNTER_H
