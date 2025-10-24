#include <iostream>
#include <vector>

using namespace std;

float pow(float x, int n) {
	float result = 1;
	if (n > 0) {
		for (int i = 0; i < n; i++)
			result *= x;
	}
	else {
		result /= pow(x, -n);
	}
	return result;
}

float teacherPow(float base, int exp) {
	if (exp < 0) {
		base = 1 / base;
		exp = -exp;
	}

	double result = 1.0;

	while (exp > 0) {
		if (exp & 1)
			result *= base;
		
		base *= base;
		exp /= 2;
	}
}

int main() {
	vector<pair<double, int>> data{ {2.0, 10}, {2.1, 3}, {2.0, -2}, {1, -2147483648} };

	for (auto& [base, exp] : data)
		cout << pow(base, exp) << endl;

	return 0;
}