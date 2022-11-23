#ifndef COUNTELAFTERMAXEL_H
#define COUNTELAFTERMAXEL_H

struct СountElAfterMaxEl
{
    void operator()(int el);
    unsigned count;
    int max;
};
#endif
