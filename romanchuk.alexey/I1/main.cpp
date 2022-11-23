#include <iostream>
#include "structure.h"

int main()
{
	int value = 0;
    values maxVal{0};
    do
    {
        std::cin >> value;
        if (!std::cin)
        {
            std::cout << "need number, programm end\n";
            std::cout << "last max value: " << maxVal.maxNum << "\n";
            return -1;
        }
        try
        {
            maxVal(value);
        }
        catch (const std::overflow_error& e)
        {
            std::cout << e.what() ;
            return -1;
        }
    } 
    while (std::cin && value);
    std::cout << "max value: " << maxVal.maxNum << "\n";
    return 1;
}