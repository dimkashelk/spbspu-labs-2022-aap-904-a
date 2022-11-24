#ifndef MAXMONO_H
#define MAXMONO_H

class MaxMono
{
public:

  unsigned int quantity = 0;

  void operator ()(int p1, int p2);

private:

  unsigned int k = 0;

};

#endif
