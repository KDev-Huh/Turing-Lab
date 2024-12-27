#include <iostream>
#include "BigInt.h"

int main()
{
	
	
	try {
		BigInt b1 = "34";
		BigInt b2 = "--1";
		std::cout << (b1 + b2).value() << std::endl;
	}
	catch (std::exception e) {
		std::cout << "에러발생 : " << e.what();
	}
}