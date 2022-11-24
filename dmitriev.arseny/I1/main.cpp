#include "DivNoRemainderFoo.h"
#include "MaxMonoFoo.h"
#include <iostream>

int main()
{
    int p2 = 0, p1 = 0;
    MaxMono maxMono;
    DivNoRemainder divNoRemainder;

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
          maxMono(p1, p2);
          divNoRemainder(p1, p2);
        }
        catch (const std::overflow_error& e)
        {
            std::cout << "Error: ";
            std::cout << e.what() << "\n";
            return 1;
        }
    }
    while (std::cin && p2);

    std::cout << "max mono increace - " << maxMono.quantity << "\n";
    std::cout << "without remainder divisible by the preceding - " 
              << divNoRemainder.quantity << "\n";

    return 0;
}
