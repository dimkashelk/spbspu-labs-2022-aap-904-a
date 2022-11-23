#ifndef structure_h
#define structure_h
struct values
{
	int predV = 0;
	int nValue = 0;
	int maxNum = 0;
	void operator()(int value);
};
struct localValuesMax
{
	int predVL = 0;
	int predPredVL = 0;
	int nValueL = 0;
	void operator()(int currentValue);
};
#endif
