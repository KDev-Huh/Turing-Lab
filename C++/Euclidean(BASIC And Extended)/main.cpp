#include <iostream>

// ax + by = gcd(a,b)
int gcd(int a, int b, int& x,int& y)
{
	// base case
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
		
	// general case
	int x1, y1;
	int g = gcd(b, a%b, x1, y1);
	std::cout <<"a = "<< a << ", b = " << b << ", x1 = " << x1 << ", y1 = " << y1 << std::endl;
	
	x = y1;
	y = x1 - (a/b) * y1;

	return g;
}

int main()
{
	int a = 18, b = 48;
	int x, y;

	std::cout << "gcd(" << a << ", "<< b << ") = " << gcd(a, b,x ,y) << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;

	return 0;
}