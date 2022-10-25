#ifndef UNTITLED1_COUNTERAFTERMAXIMUM_H
#define UNTITLED1_COUNTERAFTERMAXIMUM_H
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
#endif //UNTITLED1_COUNTERAFTERMAXIMUM_H
