#include <iostream>
#include <stdexcept>
#include "sequence1.h"
#include "elementsaftermax.h"
int main() {
	constexpr unsigned int min_int = std::numeric_limits< int >::min();
	ElementsAfterMax{ 0,min_int };
	int curr = 0;
	ElementsMoreThanPrev(curr);
	do {
		std::cin >> curr;
		if (!std::cin){
			std::cout << "Error";
			return 1;
		}
		if (std::cin){
			try {
				ElementsMoreThanPrev(curr);
				ElementsAfterMax(curr);
			}
		catch (const std::overflow_error& err){
			std::cout << err.what();
			return 2;
		}
	}
	} while (curr && std::cin);
	
	std::cout << ElementsMoreThanPrev.cnt << std::endl;
	std::cout << ElementsAfterMax.cnt << std::endl;
	return 0;

}
