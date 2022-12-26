#include <iostream>
#include "finder_same_elements_in_two_strings.h"

void finderSameElementsInTwoStrings(const char *first_string, const char *second_string, size_t size_first_string, size_t size_sec_string)
{
	size_t final_size = size_first_string + size_sec_string;
	char tmp_string[final_size];
	size_t cnt = -1;
	for (size_t i = 0; i < size_first_string; ++i)
	{
		for (size_t j = 0; j < size_sec_string; ++j)
		{
			if (first_string[i] == second_string[j])
			{
				cnt++;
				tmp_string[cnt] = first_string[i];
			}
		}
	}

	char result_string[cnt];
	for (int i = 0; i < cnt; ++i)
	{
		tmp_string[i] = result_string[i];
	}
	for (size_t i = 0; i <= final_size; ++i)
	{
		std::cout << result_string[i] << " ";
	}
}
