#include <iostream>
#include <cstddef>
#include <fstream>
#include "cnt.max.elem.h"
#include "left.shift.mover.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: That's more than actually arguments count need in this programm" << std::endl;
		return 1;
	}
	if (argc == 1)
	{
		std::cerr << "Error: No file name" << std::endl;
		return 1;
	}
	const size_t static_array_size = 11;
	int static_array[static_array_size] = { 5, 5, 5, 90, 23, 90, 3, 4, 5, 90, 11 };

	std::cout << "CounterMax Elements for Static Array" << std::endl;
	std::cout << CounterMaxElement(static_array, static_array_size)<< std::endl;

	size_t wanted_shift = 0;
	std::cout << "How many left shifts do you want for static array ?"<< std::endl;
	std::cin >> wanted_shift;
	std::cout << "LeftShiftMover for Static Array" << std::endl;
	int* pointer = LeftShiftMover(static_array, static_array_size, wanted_shift);
	for (size_t i = 0; i < static_array_size; ++i)
	{
		std::cout << pointer[i] << "\t";
	}
	std::cout << "\n";

	size_t dynamic_array_size = 0;
	std::cout << "Enter the size of dynamic array :" << std::endl;
	std::cin >> dynamic_array_size;
	int* dynamic_array = new int[dynamic_array_size];
	for (size_t i = 0; i < dynamic_array_size; ++i)
	{
	    dynamic_array[i] = rand();
	}
	std::cout << "CounterMax Elements for Dynamic Array" << std::endl;
	std::cout << CounterMaxElement(dynamic_array, dynamic_array_size) << std::endl;
	std::cout << "How many left shifts do you want for dynamic array ?"<< std::endl;
	size_t wanted_shift_dynamic_array = 0;
	std::cin >> wanted_shift_dynamic_array;
	std::cout << "LeftShiftMover for Dynamic Array" << std::endl;
	for (size_t i = 0; i < dynamic_array_size; ++i)
	{
		std::cout << dynamic_array[i] << "\t";
	}
	std::cout << "\n";
	int* pointer_dyn = LeftShiftMover(dynamic_array, dynamic_array_size, wanted_shift_dynamic_array);
	for (size_t i = 0; i < dynamic_array_size; ++i)
	{
		std::cout << pointer_dyn[i] << "\t";
	}
	std::cout << "\n";
	delete [] dynamic_array;

	//for array from the file

	std::ifstream file(argv[1]);
	if (file.fail())
	{
		std::cerr << "Error with open file";
		return 1;
	}
	while (!file.eof())
	{
		size_t size_of_file = 0;
		file >> size_of_file;
		if(!file)
		{
			std::cerr << "Error with reading file";
			return 1;
		}
		int* inputArr = new int[size_of_file];
		for (size_t i = 0; i < size_of_file; ++i)
		{
			file >> inputArr[i];
			if (!file)
			{
				std::cerr << "Problem with data of file";
				delete [] inputArr;
				return 1;
			}
		}
		std::cout << "CounterMax Elements for File Array" << std::endl;
		std::cout << CounterMaxElement(inputArr,size_of_file)<< std::endl;
		size_t wanted_shift_file = 0;
		std::cin >> wanted_shift_file;
		int* pointer_file_array = LeftShiftMover(inputArr, size_of_file, wanted_shift_file);
		for (size_t i = 0; i < size_of_file; ++i)
		{
			std::cout << pointer_file_array[i] << "\t";
		}
		std::cout << "\n";
		delete [] inputArr;
	}
	return 0;
}