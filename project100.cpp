#include <iostream>
#include <vector>
#include <cmath>  // math.h

using vfact = std::vector<std::pair<int, int> >;
using uint64 = unsigned long long int;

vfact& factor(vfact& factors, int n)
{
	int e, t = n;
	int l = sqrt(n);

	for (int i = 2; i <= l; i++)
	{
		e = 0;
		if (t % i == 0)
		{
			while (t % i == 0)
			{
				e++;
				t /= i;
			}

			factors.push_back({ i, e });
		}
	}

	if (t > 1)
		factors.push_back({ t, 1 });

	return factors;
}


uint64 fgcd(const vfact& m, const vfact& n)
{
	uint64 prod = 1;
	int ms = 0 , ns = 0;
	
	while (ms < m.size() && ns < n.size())
	{
		if (m[ms].first < n[ns].first)
			ms++;
		else if (m[ms].first > n[ns].first)
			ns++;
		else {
			if (m[ms].second <= n[ns].second)
				prod *= pow(m[ms].first, m[ms].second);
			else
				prod *= pow(n[ns].first, n[ns].second);
			ms++;
			ns++;
		}
	}

	return prod;
}

void printPrimFactors(const vfact& factors)
{
	for (const auto& n : factors)
		std::cout << n.first << "^" << n.second << " * ";

	std::cout << "\b\b \n";
}

int main()
{
	int m = 36;
	int n = 60;
	vfact vf36, vf60;

	factor(vf36, m);
	factor(vf60, n);

	printPrimFactors(vf36);
	printPrimFactors(vf60);

	std::cout << "gcd = " << fgcd(vf36, vf60) << std::endl;

	return 0;
}