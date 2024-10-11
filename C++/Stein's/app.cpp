#include <iostream>

int gcd(int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;

	int e = 0;
	while (((a | b) & 1) == 0)
	{
		a >>= 1;
		b >>= 1;
		e++;
	}

	while ((a & 1) == 0)
		a >>= 1;

	do {
		while ((b & 1) == 0)
			b >>= 1;

		if (a > b)
		{
			int t = a;
			a = b;
			b = t;
		}

		b = (b - a);
	} while (b != 0);

	return a << e;
}

int main()
{
	int m = 18624, n = 48936;

	std::cout << gcd(m, n) << std::endl;

	return 0;
}