#include <iostream>
#include "structure.h"

int main()
{
    int value = 0;
    values maxVal{ 0 };
    do
    {
        std::cin >> value;
        if (!std::cin)
        {
            std::cout << "need number, programm end\n";
            std::cout << "last max value: " << maxVal.maxNum << "\n";
            return -1;
        }
        maxVal(value);
    } while (std::cin && value);
    std::cout << "max value: " << maxVal.maxNum << "\n";
    return 1;
}