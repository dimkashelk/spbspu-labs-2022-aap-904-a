#ifndef SEQUENCE_MAX_H
#define SEQUENCE_MAX_H

class Lab_I1_T2
{
public:
  Lab_I1_T2();
  void operator()(int n);
  int get_count_after_max() const;
private:
  int n;
  int max_n;
  int count_after_max;
};

#endif
