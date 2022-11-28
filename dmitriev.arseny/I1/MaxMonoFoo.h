#ifndef MAXMONO_H
#define MAXMONO_H

struct MaxMono
{
public:
  unsigned int quantity = 0;

  void operator()(int current);
private:
  unsigned int k = 0;
  int previous = 0;
};

#endif
