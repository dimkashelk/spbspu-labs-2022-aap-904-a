#ifndef LENGTHMAX_H
#define LENGTHMAX_H

struct LengthMax
{
    int count = 1;
    int length_max = 0;

    void operator()(int value, int predV);
};

#endif
