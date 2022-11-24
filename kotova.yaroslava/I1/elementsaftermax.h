#ifndef ELEMENTSAFTERMAX_H
#define ELEMENTSAFTERMAX_H
struct ElementsAfterMax {
	int max;
	unsigned int cnt;
	void operator()(int curr);
};
#endif
