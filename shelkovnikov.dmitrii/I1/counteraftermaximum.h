#ifndef SPBSPU_LABS_2022_AAP_904_A_COUNTERAFTERMAXIMUM_H
#define SPBSPU_LABS_2022_AAP_904_A_COUNTERAFTERMAXIMUM_H
class CounterAfterMaximum
{
public:
    CounterAfterMaximum(int number);
    void operator()(int next);
    unsigned int get_count() const;
private:
    unsigned int count;
    int maximum;
};
#endif
