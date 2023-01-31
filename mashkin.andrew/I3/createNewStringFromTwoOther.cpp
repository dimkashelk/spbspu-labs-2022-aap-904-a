#include <iostream>
#include <cctype>
#include "createNewStringFromTwoOther.h"

char* createNewStringFromTwoOther(char* newStringFromTwoOther, const char* cstring1, const char* cstring2)
{
	size_t capacity = 10;
	newStringFromTwoOther = new char[capacity];
	size_t size = 0;
	for (const char* i = cstring1; *i; i++)
	{
		if (std::isdigit(*i))
		{
			bool repetition = false;
			for (char* j = newStringFromTwoOther; *j; j++)
			{
				if (*j == *i)
				{
					repetition = true;
					break;
				}
			}
			if (!repetition)
			{
				for (const char* j = cstring2; *j; j++)
				{
					if (*j == *i)
					{
						if (size == capacity)
						{
							try
							{
								char* newstr = new char[capacity + 10];
								for (char* a = newStringFromTwoOther, *b = newstr; a != newStringFromTwoOther + size; ++a, ++b)
								{
									*b = *a;
								}
								delete[] newStringFromTwoOther;
								newStringFromTwoOther = newstr;
								capacity += 10;
								delete[] newstr;
							}
							catch (...)
							{
								delete[] newStringFromTwoOther;
								throw std::exception("Error");
							}
						}
						newStringFromTwoOther[size] = *j;
						size++;
					}
				}
			}
		}
	}
	newStringFromTwoOther[size] = '\0';
	return newStringFromTwoOther;
}
