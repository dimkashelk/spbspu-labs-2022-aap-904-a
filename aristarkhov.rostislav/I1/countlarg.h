#ifndef COUNT_LARG_H
#define COUNT_LARG_H

struct CountLarg
{
	int larg_val;
	unsigned int count_amount;

	void operator()(int curr_val);
};

#endif