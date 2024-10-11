#include <iostream>
#include <numeric>

int findValue(int x, int y, int z)
{
	int g = std::gcd(y, z);

	return (x * g) / std::gcd(x, g);
}

int main()
{
	int x = 30, y = 40, z = 400;

	std::cout << findValue(x, y, z) << std::endl;
	
	return 0;
}
