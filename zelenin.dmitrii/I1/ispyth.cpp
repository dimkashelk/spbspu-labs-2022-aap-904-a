#include "ispyth.h"

bool isPyth(int x, int y, int z)
{
	if (x * x + y * y == z * z)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
