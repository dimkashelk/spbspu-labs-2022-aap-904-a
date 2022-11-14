#include "supplement.h"
#include <iostream>
#include <cmath>

void MaxSameValue::operator()(int value) {

		if (value == value_before)
		{
			number_of_same_value += 1;
		}
		else
		{			
			max_number_of_same_value = std::max(number_of_same_value, max_number_of_same_value);
			number_of_same_value = 1;
		}

	value_before = value;
}

void MaxGrowingSequence::operator()(int value) {
	if (value > value_before)
	{
		number_of_growing_sequence += 1;
	}
	else
	{
		max_number_of_growing_sequence = std::max(number_of_growing_sequence, max_number_of_growing_sequence);
		number_of_growing_sequence = 1;
	}
	value_before = value;
}