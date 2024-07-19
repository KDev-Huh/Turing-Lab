#include <iostream>
#include "fract.h"

int main()
{
	try {
		Fract fr1(4, 12), fr2(5, -8), fr3;

		std::cin >> fr3;
		std::cout << fr3 << std::endl;
		std::cout << fr1 << " " << fr2 << std::endl;
		std::cout << (fr1 * fr2) << std::endl;
		std::cout << fr1 << " + " << fr2 << " = " << (fr1 + fr2) << " " << (fr1 + fr2) * fr3 << std::endl;
		std::cout << fr1 << " - " << fr2 << " = " << (fr1 - fr2) << std::endl;
		std::cout << fr1 << " / " << fr2 << " = " << (fr1 / fr2) << std::endl;
	}
	catch (std::exception ex) 
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}