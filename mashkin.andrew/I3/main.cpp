#include <iostream>
#include <cstddef>
#include "createCString.h"

main()
{
	char* string1 = nullptr;
	try
	{
		string1 = createCString();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
		return 1;
	}
	char* string2 = nullptr;
	try
	{
		string2 = createCString();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
		return 1;
	}
	char* cstring = nullptr;
	try
	{
		cstring = createCString();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
		return 1;
	}
	delete[] string1;
	delete[] string2;
	delete[] cstring;
  return 0;
}
