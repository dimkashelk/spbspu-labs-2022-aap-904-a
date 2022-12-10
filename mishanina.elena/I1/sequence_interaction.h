#ifndef SEQUENCE_INTERACTION_H
#define SEQUENCE_INTERACTION_H

class Lab_I1
{
public:
  Lab_I1();
  void operator()(int n);
  int get_count() const;
private:
  int n;
  int old_n;
  int cur_n;
  int new_n;
  int count;
};

#endif
