#include <iostream>
#include <vector>
#include <numeric>
/*
// 최대공약수구하기
int rgcd(int a, int b)
{
	if (b == 0)
		return a;
	return (b, a % b);
}

int gcd(int a, int b)
{
	if (a > b)
		return rgcd(a, b);
	else
		return rgcd(b, a);
}
*/

int lcm(std::vector<int> arr)
{
	int ans = arr[0];

	for (int i = 1; i < arr.size(); i++)
		ans = (ans*arr[i])/std::gcd(ans, arr[i]);

	return ans;
}

int lcm(std::vector<int> arr)
{	
	// accumulate(a, b, c)a는 처음 시작값 b는 마지막 값 c는 더하기전 초기값
	return std::accumulate(arr.begin(), arr.end(), 1,
		[](int x, int y) {return std::lcm(x, y); });
		// [](int x, int y) { return (x * y) / std::gcd(x, y);  }); 
}

int main()
{
	std::vector<int> arr1{ 1, 2, 8, 3 };
	std::vector<int> arr2{ 2, 7, 3, 9, 4 };

	std::cout << lcm(arr1) << std::endl;
	std::cout << lcm(arr2) << std::endl;

	return 0;
}

