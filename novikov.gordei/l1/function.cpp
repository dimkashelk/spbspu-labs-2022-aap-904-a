#include "function.h"
#include <cstdlib>
#include <cstring>

bool isNumberValid(char* str, long &number)
{
	char *endptr;
	number = strtol(str, &endptr, 10);
	return (strlen(endptr) == 0);
}

bool isPythagoreanTriples(long x, long y, long z)
{
	return (x * x + y * y == z * z);
}