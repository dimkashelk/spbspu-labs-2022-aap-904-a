#ifndef LEN_EVEN_COUNT_H
#define LEN_EVEN_COUNT_H

struct LenEvenCounter
{
	int count_even;
	unsigned int count_len_even;

	void operator()(int curr_value);
};

#endif