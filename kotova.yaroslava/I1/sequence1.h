#ifndef SEQUENCE1_H
#define SEQUENCE1_H
struct ElementsMoreThanPrev {
	int prev;
	unsigned int cnt;
	void operator()(int curr);
};
#endif