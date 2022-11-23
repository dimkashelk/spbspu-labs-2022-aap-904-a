#include <iostream>
#include "DivNoRemainderFoo.h"
#include "MaxMonoFoo.h"

int main()
{
    int p2 = 0, p1 = 0;
    unsigned int k = 0;
    unsigned int maxMono = 0;
    unsigned int divNoRemainder = 0;
    do
    {
        p1 = p2;
        std::cin >> p2;
        if (!std::cin)
        {
            std::cout << "Inp error" << "\n";
            return 1;
        }
        if (p2 == 0)
        {
            break;
        }
        try
        {
            defMaxMono(maxMono, k, p1, p2);
            defDivNoRemainder(divNoRemainder, p1, p2);
        }
        catch (const std::overflow_error& e)
        {
            std::cout << "Error: ";
            std::cout << e.what() << "\n";
            return 1;
        }
    } while (std::cin && p2);

    std::cout << "max mono increace - " << maxMono << "\n";
    std::cout << "without remainder divisible by the preceding - " << divNoRemainder << "\n";

    return 0;
}
